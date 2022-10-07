#include "T1.h"


int fork_start_x_pos=120;
int fork_start_y_pos=40;
int current_fork_x=0;
int current_fork_y=0;
int fork_size=5;
int fork_stop=20;

void alarm_icon(int start_point_x, int start_point_y)
{    
    plot1(start_point_x, start_point_y-4);
    plot1(start_point_x, start_point_y-3);
    plot1(start_point_x, start_point_y-2);
    plot1(start_point_x, start_point_y-1);
    plot1(start_point_x, start_point_y);
    plot1(start_point_x, start_point_y+2);
    plot1(start_point_x, start_point_y+3);
}

void error_icon(int start_point_x, int start_point_y)
{    
    plot1(start_point_x, start_point_y-4);
    plot1(start_point_x-1, start_point_y-3);
    plot1(start_point_x+1, start_point_y-3);    
    plot1(start_point_x-2, start_point_y-2);
    plot1(start_point_x+2, start_point_y-2);
    plot1(start_point_x-3, start_point_y-1);
    plot1(start_point_x+3, start_point_y-1);
    plot1(start_point_x-2, start_point_y);
    plot1(start_point_x+2, start_point_y);
    plot1(start_point_x-1, start_point_y+2);
    plot1(start_point_x+1, start_point_y+2);
    plot1(start_point_x, start_point_y+3);
}

void back_arrow_icon(int start_point_x, int start_point_y)
{   
    plot1(start_point_x, start_point_y);
    plot1(start_point_x+1, start_point_y);
    plot1(start_point_x+2, start_point_y);
    plot1(start_point_x+3, start_point_y);
    plot1(start_point_x+4, start_point_y);
    plot1(start_point_x+5, start_point_y);
    
    plot1(start_point_x+1, start_point_y+1);
    plot1(start_point_x+2, start_point_y+1);
    plot1(start_point_x+3, start_point_y+1);
    plot1(start_point_x+4, start_point_y+1);
    
    plot1(start_point_x+2, start_point_y+2);
    plot1(start_point_x+3, start_point_y+2);
}

void front_arrow_icon(int start_point_x, int start_point_y)
{   
    plot1(start_point_x, start_point_y);
    plot1(start_point_x+1, start_point_y);
    plot1(start_point_x+2, start_point_y);
    plot1(start_point_x+3, start_point_y);
    plot1(start_point_x+4, start_point_y);
    plot1(start_point_x+5, start_point_y);
    
    plot1(start_point_x+1, start_point_y-1);
    plot1(start_point_x+2, start_point_y-1);
    plot1(start_point_x+3, start_point_y-1);
    plot1(start_point_x+4, start_point_y-1);
    
    plot1(start_point_x+2, start_point_y-2);
    plot1(start_point_x+3, start_point_y-2);
}

void draw_box(int start_point_x, int start_point_y, int end_point_x, int end_point_y)
{
    int i=0;
    int j=0;
    
    for (i = start_point_x; i < end_point_x; i++ )
    {
        for (j = start_point_y; j < end_point_y; j++ )
        {
            plot1(i, j);
        }
    }
}

void draw_empty_box(int start_point_x, int start_point_y, int end_point_x, int end_point_y)
{
    int i=0;
    int j=0;
    
    for (i = start_point_x; i < end_point_x; i++ )
    {
        if(i==start_point_x || i==end_point_x-1)
        {
            for (j = start_point_y; j < end_point_y; j++ )
            {
                plot1(i, j);
            }
        }
        else
        {
            plot1(i, start_point_y);
            plot1(i, end_point_y-1);
        }
    }
}

void clear_box(int start_point_x, int start_point_y, int end_point_x, int end_point_y)
{
    int i=0;
    int j=0;
    
    for (i = start_point_x; i < end_point_x; i++ )
    {
        for (j = start_point_y; j < end_point_y; j++ )
        {
            plot0(i, j);
        }
    }
}

void initial_draw()
{
    goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
    goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
    goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');
    
    //Fork
    draw_box(fork_start_x_pos, fork_start_y_pos, fork_start_x_pos+fork_size, fork_start_y_pos+fork_size);
    current_fork_x=fork_start_x_pos;
    current_fork_y=fork_start_y_pos;
    draw_empty_box(fork_start_x_pos-fork_stop-1, fork_start_y_pos-fork_stop-1, fork_start_x_pos+fork_size+fork_stop+1, fork_start_y_pos+fork_size+fork_stop+1);

    //Icons
    alarm_icon(200, 20);
}

void blockVitesse(unsigned char vitesseCourante)
{
    VITESSE_PLUS = vitesseCourante;
}

void stopVitess(unsigned char  vitesseCourante)
{
    int cpt; 
    char newVitesse;
    
    while (vitesseCourante != 0)
    {
        cpt ++;
        if ((cpt %20)==1)
        {
            vitesseCourante --;
            newVitesse = setBit(newVitesse,vitesseCourante);
            goto_lico(5,0);
            draw_string("Vitesse:");
            
        if (VITESSE_PLUS==0)
            vitesse++;
        if (VITESSE_MOINS==0)
            vitesse--;
        draw_hex8(vitesse);
            
            
        }
    }
}

void tache1()
{
    unsigned char i;
    
    unsigned int alarmeEnCours = 0;
    
    di();
    initialisation_des_ports();
    initialisation_afficheur();
    clear_text();
    clear_graphics();
    init_rxtx();
    Init(SEM_RXTX);
    RXTX_libre=1;
    TXREG1='R';
    ei();

    LED_R=0;LED_G=0;LED_B=0;

    vitesse=0;
    batterie=120;
    n_octet_badge=0;

    goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
    goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
    goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');
    
    //Fork
    draw_box(fork_start_x_pos, fork_start_y_pos, fork_start_x_pos+fork_size, fork_start_y_pos+fork_size);
    current_fork_x=fork_start_x_pos;
    current_fork_y=fork_start_y_pos;
    draw_empty_box(fork_start_x_pos-fork_stop-1, fork_start_y_pos-fork_stop-1, fork_start_x_pos+fork_size+fork_stop+1, fork_start_y_pos+fork_size+fork_stop+1);
            
    TP_appui=0;
    alarme_pannel=0;
         
    int flash_interval_alarm=0;
    int flash_interval_error=0;
    
    while(1)
    {
        
        //Alarm icon flash
        if (alarme_active != 0x00)
        {
        flash_interval_alarm++;
        if (flash_interval_alarm = 4000)
        {
            draw_empty_box(190, 10, 210, 30);
            alarm_icon(200, 20);
        }
        if (flash_interval_alarm = 8000)
        {
            clear_box(190, 10, 210, 30);
            flash_interval_alarm=0;
        }
        }
        
        //Error icon flash
        if (error_active != 0x00)
        {
        flash_interval_error++;
        if (flash_interval_error = 4000)
        {
            draw_empty_box(190, 35, 210, 55);
            error_icon(200, 45);
        }
        if (flash_interval_error = 8000)
        {
            clear_box(190, 35, 210, 55);
            flash_interval_error=0;
        }  
        }
                
        /*if (flagChoc==1)    
        {
            goto_lico(11,0);
        }*/
        
        /*if(flagVitesse == 1)
        {
            //blockVitesse(32); 
            goto_lico(11,0);
            draw_string("alarme_vitesse="); 
            draw_hex8((alarme_active >> 7) & 0x01);
            flagVitesse = 0;
        }*/
        
        goto_lico(0,0);
        draw_string("Marche:");
        if (MARCHE_AVANT==0 && error_active==0)
        {
            draw_string("AV");
            clear_box(120, 67, 130, 73);
            front_arrow_icon(120, 70);
        }
        else
        {
            if (MARCHE_ARRIERE==0 && error_active==0)
            {
                draw_string("AR");
                clear_box(120, 67, 130, 73);
                back_arrow_icon(120, 70);
            }
            else
            {
                draw_string("N ");
                clear_box(120, 67, 130, 73);
            }
        }

        goto_lico(1,0);
        draw_string("Siege:");
        if (SIEGE==0)
        {draw_char('1');}
        else
        {draw_char('0');}

        goto_lico(2,0);
        draw_string("Temp. Eau:");
        draw_hex8(tempeau);

        goto_lico(3,0);
        draw_string("Temp. Huile:");
        draw_hex8(temphuile);

        goto_lico(4,0);
        draw_string("Choc:");
        if (CHOC==0)
            draw_char('1');
        else
            draw_char('0');

        goto_lico(5,0);
        draw_string("Vitesse:");
        draw_hex8(vitesse);
        goto_lico(10,15);
        draw_string("Vitesse reel:");
        draw_hex8(vitesseReel);

        goto_lico(6,0);
        draw_string("Batterie:");
        draw_hex8(batterie);
        goto_lico(11,15);
        draw_string("Batterie reel:");
        draw_hex8(batterieReel);
        goto_lico(12,15);
        draw_string("E(c):");
        draw_hex8(eauReel);
        goto_lico(12,25);
        draw_string("H(c):");
        draw_hex8(huileReel);

        goto_lico(7,0);
        if (FREIN_A_MAIN==0)
            draw_string("((!))");
        else
            draw_string("     ");

        goto_lico(8,0);
        draw_string("Badge:");
        if (n_octet_badge==0)
            draw_string(" AUCUN              ");
        else
        {
            for (i=0;i<n_octet_badge;i++)
            {
                draw_hex8(badge[i]);
            }
        }

        goto_lico(9,0);
        draw_string("X-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_X));

        goto_lico(10,0);
        draw_string("Y-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_Y));

        if (TP_appui==1)
        {
            goto_lico(0,20);
            draw_string("x=");
            draw_hex8(TP_x);
            draw_string(" y=");
            draw_hex8(TP_y);
            plot1(TP_x,TP_y);
        }
        else
        {
            Nop();
        }
        
        
        //draw_box(100, 100, 110, 110);
        //draw_line_x(120, 120, 140);
        //draw_line_y(140, 140, 160);
        //draw_fork(120, 40);
        
        //Fork
        if (lecture_8bit_analogique(JOYSTICK_X) == 0xFF && (current_fork_x+1)<(fork_start_x_pos+fork_stop))
        {
            clear_box(current_fork_x, current_fork_y, current_fork_x+fork_size, current_fork_y+fork_size);
            draw_box(current_fork_x+1, current_fork_y, current_fork_x+fork_size+1, current_fork_y+fork_size);
            current_fork_x=current_fork_x+1;
        }
        if (lecture_8bit_analogique(JOYSTICK_X) == 0x00 && (current_fork_x-1)>(fork_start_x_pos-fork_stop))
        {
            clear_box(current_fork_x, current_fork_y, current_fork_x+fork_size, current_fork_y+fork_size);
            draw_box(current_fork_x-1, current_fork_y, current_fork_x+fork_size-1, current_fork_y+fork_size);
            current_fork_x=current_fork_x-1;
        }
        if (lecture_8bit_analogique(JOYSTICK_Y) == 0x00 && (current_fork_y+1)<(fork_start_y_pos+fork_stop))
        {
            clear_box(current_fork_x, current_fork_y, current_fork_x+10, current_fork_y+fork_size);
            draw_box(current_fork_x, current_fork_y+1, current_fork_x+fork_size, current_fork_y+fork_size+1);
            current_fork_y=current_fork_y+1;
        }
       if (lecture_8bit_analogique(JOYSTICK_Y) == 0xFF && (current_fork_y-1)>(fork_start_y_pos-fork_stop))
        {
            clear_box(current_fork_x, current_fork_y, current_fork_x+fork_size, current_fork_y+fork_size);
            draw_box(current_fork_x, current_fork_y-1, current_fork_x+fork_size, current_fork_y+fork_size-1);
            current_fork_y=current_fork_y-1;
        }
        
        goto_lico(11,0);
        draw_string("chocint=");
        draw_hex8(flagChoc);
        goto_lico(12,0);
        draw_string("siegeint=");
        draw_hex8(flagSiege);
        goto_lico(13,0);
        draw_string("avantint=");
        draw_hex8(flagMarcheAvant);
        goto_lico(14,0);
        draw_string("arriereint=");
        draw_hex8(flagMarcheArriere);
        
        if(alarme_pannel==0xFF)
        {
            clear_text();
            clear_graphics();
            while (alarme_pannel==0xFF)
            {
                //Alarme et erreurs
                draw_empty_box(190, 10, 210, 30);
                alarm_icon(200, 20);
                goto_lico(0,0);
                draw_string("alarme_eau=");
                draw_hex8((alarme_active >> 0) & 0x01);
                goto_lico(1,0);
                draw_string("alarme_huile=");
                draw_hex8((alarme_active >> 1) & 0x01);
                goto_lico(2,0);
                draw_string("alarme_choc=");
                draw_hex8((alarme_active >> 2) & 0x01);
                goto_lico(3,0);
                draw_string("alarme_batterie=");
                draw_hex8((alarme_active >> 3) & 0x01);
                goto_lico(0,20);
                draw_string("alarme_cle=");
                draw_hex8((alarme_active >> 4) & 0x01);
                goto_lico(1,20);
                draw_string("alarme_frein=");
                draw_hex8((alarme_active >> 5) & 0x01);
                goto_lico(2,20);
                draw_string("alarme_siege=");
                draw_hex8((alarme_active >> 6) & 0x01);
                goto_lico(4,20);
                draw_string("choc_time=");
                draw_hex8(choc_time_1);
                draw_hex8(choc_time_2);
                draw_hex8(choc_time_3);
                draw_hex8(choc_time_4);
                
                goto_lico(6,0);
                draw_string("erreur_choc=");
                draw_hex8((error_active >> 2) & 0x01);
                goto_lico(7,0);
                draw_string("erreur_batterie=");
                draw_hex8((error_active >> 2) & 0x01);
                goto_lico(8,0);
                draw_string("erreur_siege=");
                draw_hex8((error_active >> 2) & 0x01);
                goto_lico(6,20);
                draw_string("erreur_eau=");
                draw_hex8((error_active >> 2) & 0x01);
                goto_lico(7,20);
                draw_string("erreur_huile=");
                draw_hex8((error_active >> 2) & 0x01);
            }
            clear_text();
            clear_graphics();
            goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
            goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
            goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');
    
            //Fork
            draw_box(fork_start_x_pos, fork_start_y_pos, fork_start_x_pos+fork_size, fork_start_y_pos+fork_size);
            current_fork_x=fork_start_x_pos;
            current_fork_y=fork_start_y_pos;
            draw_empty_box(fork_start_x_pos-fork_stop-1, fork_start_y_pos-fork_stop-1, fork_start_x_pos+fork_size+fork_stop+1, fork_start_y_pos+fork_size+fork_stop+1);

            //Icons
            draw_empty_box(190, 10, 210, 30);
            alarm_icon(200, 20);
        }
                
    }
}