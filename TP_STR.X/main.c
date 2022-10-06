#include "main.h"

void main()
{
    initialisation_des_ports();
    initialisation_du_systeme();
    Init(SEM_CAN);

        // D�marrage du syst�me
    T0CONbits.TMR0ON=1; //D�marrage du Timer0
    T0IF=1; // For�age du d�clenchement de la premi�re IT
    ei(); //Activation des interruptions => D�marrage du syst�me

        // La suite ne sera jamais �x�cut�e
    while(1)
        Nop();
}

void PWM1_Init(){

    //PWM
    TRISJ7 = 0;		/* Set CCP1 pin as output for PWM out */
    PR2 = 255;		/* Load period value : about 10.8KHz */
    CCPR1L = 255;	/* load duty cycle value */
    T2CON = 0;		/* No pre-scalar, timer2 is off */
    CCP1CON = 0x0C;	/* Set PWM mode and no decimal for PWM */
    TMR2 = 0;		/* Clear Timer2 initially */
    TMR2ON = 1;		/* Timer ON for start counting*/
    
}

void initialisation_des_ports()
{
// D�sactivation du bus externe
    MEMCON=0xA0;    //ebdis=1 bus d�sactiv� (sauf en cas d'acc�s externe)

// D�sactivation des fonctions analogiques
    ANCON0=0x00;
    ANCON1=0x00;
    ANCON2=0x00;
    ANCON0bits.ANSEL0=1; // RA0 analogique Touch pad BOTTOM (y)
    ANCON0bits.ANSEL1=1; // RA1 analogique Touch pad LEFT (x)
    ANCON0bits.ANSEL2=1; // RA2 analogique Temp�rature d'eau
    ANCON0bits.ANSEL3=1; // RA3 analogique Temp�rature d'huile
    ANCON1bits.ANSEL10=1; // RF5 analogique Joystick (x)
    ANCON1bits.ANSEL11=1; // RF6 analogique Joystick (y)


// Valeur initiale des ports en sortie
    LED_R=1;
    LED_G=1;
    LED_B=1;

// D�fintion du sens des ports
    TRISCbits.TRISC2=0; //LED_R en sortie
    TRISCbits.TRISC1=0; //LED_G en sortie
    TRISGbits.TRISG0=0; //LED_B en sortie
    TRISGbits.TRISG3=0; //DRIVEA en sortie
    TRISGbits.TRISG4=0; //DRIVEB en sortie
    TRISDbits.TRISD2=0; //STID_CLOCK en sortie
    TRISDbits.TRISD3=0; //STID_READ en sortie
    
// Buzzer en sortie
    TRISJbits.TRISJ7=0;

// Mise en place des pull up
    INTCON2bits.RBPU=0; // Pull up PORTB activ�
    PADCFG1bits.REPU=1; // Pull up PORTE activ�

    PWM1_Init();
    
    //Initialise Interrupts
    RCONbits.IPEN = 1; //Enable interrupt priority levels
        
    //INTCONbits.GIE = 1;
    //INTCONbits.PEIE = 1;
    //INTCONbits.INT0IE = 1;
    
    //INTCON2bits.INTEDG0 = 1;
    //INTCON2bits.INTEDG1 = 1;
    //INTCON2bits.INTEDG2 = 1;
    
    //INTCON = 0xD0; //Enable INT0
    //INTCON2 = 0x70; //External interrupts on rising edge
    INTCON3 = 0x18; //INT1 low priority INT 2 low priority
    
}

unsigned char lecture_8bit_analogique(unsigned char channel)
{
    unsigned char ret;

    //P(SEM_CAN);
    ADCON1=0;//Vref+ = Vdd / Vref- = Vss / pas de canal negatif
    ADCON2=0x16; // Fosc/64 Left justified Tacq=4Tad(5.3�s)
    channel=channel&0x1F; // les valeurs acceptables sont 0 � 31
    channel=channel<<2;
    ADCON0=channel|0x01; //S�lection du canal et d�marrage du Module AD

    ADCON0bits.GO=1;
    while(ADCON0bits.DONE==1)
        ;

    if ((ADRESL&0x01)==0x01)
        ret=0;
    else
        ret=ADRESH;
    //V(SEM_CAN);

    return ret;
}