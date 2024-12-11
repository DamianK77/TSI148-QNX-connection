#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct register_info {

    uint16_t VENI;    
    uint16_t DEVI;    

    uint16_t CMMD;    
    uint16_t STAT;    

    uint8_t REVI;     
    uint8_t CLAS[3];  

    uint8_t CLSZ;     
    uint8_t MLAT;     
    uint8_t HEAD;     
    uint8_t reserved1; 

    uint32_t MBARL;   
    uint32_t MBARU;   

    uint32_t reserved2; 
    uint32_t reserved3; 
    uint32_t reserved4; 
    uint32_t reserved5; 
    uint32_t reserved6; 

    uint16_t SUBV;    
    uint16_t SUBI;    

    uint32_t reserved7; 
    uint8_t CAPP;      
    uint8_t reserved8[3]; 
    
    uint32_t reserved9; 
    uint8_t INTL;     
    uint8_t INTP;     
    uint8_t MNGN;     
    uint8_t MXLA;     

    uint32_t PCIXCAP; 
    uint32_t PCIXSTAT;

    uint8_t reserved11[0xFF - 0x48]; 

    uint32_t OTSAU0;
    uint32_t OTSAL0;
    uint32_t OTEAU0;
    uint32_t OTEAL0;
    uint32_t OTOFU0;
    uint32_t OTOFL0;
    uint32_t OTBS0;
    uint32_t OTAT0;

    uint32_t OTSAU1;  
    uint32_t OTSAL1;  
    uint32_t OTEAU1;  
    uint32_t OTEAL1;  

    uint32_t OTOFU1;  
    uint32_t OTOFL1;  

    uint32_t OTBS1;   
    uint32_t OTAT1;   

    uint32_t OTSAU2;  
    uint32_t OTSAL2;  

    uint32_t OTEAU2;  
    uint32_t OTEAL2;  

    uint32_t OTOFU2;  
    uint32_t OTOFL2;  

    uint32_t OTBS2;   
    uint32_t OTAT2;   
    uint32_t OTSAU3;  
    uint32_t OTSAL3;  

    uint32_t OTEAU3;  
    uint32_t OTEAL3;  

    uint32_t OTOFU3;  
    uint32_t OTOFL3;  

    uint32_t OTBS3;   
    uint32_t OTAT3;   

    uint32_t OTSAU4;  
    uint32_t OTSAL4;  

    uint32_t OTEAU4;  
    uint32_t OTEAL4;  

    uint32_t OTOFU4;  
    uint32_t OTOFL4;

    uint32_t OTBS4;   
    uint32_t OTAT4;

    uint32_t OTSAU5;  
    uint32_t OTSAL5;  

    uint32_t OTEAU5;  
    uint32_t OTEAL5;  

    uint32_t OTOFU5;  
    uint32_t OTOFL5;  

    uint32_t OTBS5;  
    uint32_t OTAT5;   

    uint32_t OTSAU6;  
    uint32_t OTSAL6;  

    uint32_t OTEAU6;  
    uint32_t OTEAL6;  
    uint32_t OTOFU6; 
    uint32_t OTOFL6;  

    uint32_t OTBS6;   
    uint32_t OTAT6;   

    uint32_t OTSAU7;  
    uint32_t OTSAL7;  
    uint32_t OTEAU7;  
    uint32_t OTEAL7;  

    uint32_t OTOFU7;  
    uint32_t OTOFL7;  
    uint32_t OTBS7;   
    uint32_t OTAT7;   
    
    uint32_t reservedC;

    uint32_t VIACK1;  
    uint32_t VIACK2;  
    uint32_t VIACK3;  
    uint32_t VIACK4;  
    uint32_t VIACK5;  
    uint32_t VIACK6;  
    uint32_t VIACK7;  

    uint32_t RMWAU;   
    uint32_t RMWAL;   
    uint32_t RMWEN;   
    uint32_t RMWC;    
    uint32_t RMWS;    

    uint32_t VMCTRL;  
    uint32_t VCTRL;   
    uint32_t VSTAT;   

    uint32_t PCSR;    

    uint32_t reservedD;
    uint64_t reserved22;

    uint32_t VMEFL;    
    
    uint64_t reservedE;

    uint32_t VEAU;       
    uint32_t VEAL;      
    uint32_t VEAT;       

    uint32_t reserved12;  


    uint32_t EDPAU;      
    uint32_t EDPAL;      
    uint32_t EDPXA;      
    uint32_t EDPXS;     
    uint32_t EDPAT;  

    uint64_t reservedF;  
    uint64_t reserved23[14];

    uint32_t ITSAU0;     
    uint32_t ITSAL0;     
    uint32_t ITEAU0;     
    uint32_t ITEAL0;     
    uint32_t ITOFU0;     
    uint32_t ITOFL0;     
    uint32_t ITAT0;     

   uint32_t reserved13;

    uint32_t ITSAU1;     
    uint32_t ITSAL1;     
    uint32_t ITEAU1;     
    uint32_t ITEAL1;     
    uint32_t ITOFU1;     
    uint32_t ITOFL1;     
    uint32_t ITAT1;        

    uint32_t reserved14;

    uint32_t ITSAU2;     
    uint32_t ITSAL2;     
    uint32_t ITEAU2;     
    uint32_t ITEAL2;     
    uint32_t ITOFU2;     
    uint32_t ITOFL2;     
    uint32_t ITAT2;      

    uint32_t reserved15;

    uint32_t ITSAU3;     
    uint32_t ITSAL3;     
    uint32_t ITEAU3;     
    uint32_t ITEAL3;     
    uint32_t ITOFU3;     
    uint32_t ITOFL3;     
    uint32_t ITAT3;      

    uint32_t reserved16;

    uint32_t ITSAU4;     
    uint32_t ITSAL4;     
    uint32_t ITEAU4;     
    uint32_t ITEAL4;     
    uint32_t ITOFU4;     
    uint32_t ITOFL4;     
    uint32_t ITAT4;      

    uint32_t reserved17;

    uint32_t ITSAU5;     
    uint32_t ITSAL5;     
    uint32_t ITEAU5;     
    uint32_t ITEAL5;     
    uint32_t ITOFU5;     
    uint32_t ITOFL5;     
    uint32_t ITAT5;      

    uint32_t reserved18;


    uint32_t ITSAU6;     
    uint32_t ITSAL6;     
    uint32_t ITEAU6;     
    uint32_t ITEAL6;     
    uint32_t ITOFU6;     
    uint32_t ITOFL6;     
    uint32_t ITAT6;     

    uint32_t reserved19;

    uint32_t ITSAU7;     
    uint32_t ITSAL7;     
    uint32_t ITEAU7;     
    uint32_t ITEAL7;     
    uint32_t ITOFU7;     
    uint32_t ITOFL7;     
    uint32_t ITAT7;     

    uint32_t reserved20;
    
    uint32_t GBAU;
    uint32_t GBAL;
    uint32_t GCSRAT;
    uint32_t CBAU;
    uint32_t CBAL;
    uint32_t CRGAT;
    uint32_t CROU;
    uint32_t CROL;
    uint32_t CRAT;

    uint32_t LMBAU;
    uint32_t LMBAL;
    uint32_t LMAT;
    uint32_t BCU64; // DIFFERENT FROM DOCUMENTATION
    uint32_t BCL64; // DIFFERENT FROM DOCUMENTATION
    uint32_t BPGTR;
    uint32_t BPCTR;
    uint32_t VICR;

    uint32_t reserved21;

    uint32_t INTEN;
    uint32_t INTEO;
    uint32_t INTS;
    uint32_t INTC;
    uint32_t INTM1;
    uint32_t INTM2;

    uint64_t reservedG[20];

    uint32_t DCTL0;
    uint32_t DSTA0;
    uint32_t DCSAU0;
    uint32_t DCSAL0;
    uint32_t DCDAU0;
    uint32_t DCDAL0;
    uint32_t DCLAU0;
    uint32_t DCLAL0;
    uint32_t DSAU0;
    uint32_t DSAL0;
    uint32_t DDAU0;
    uint32_t DDAL0;
    uint32_t DSAT0;
    uint32_t DDAT0;
    uint32_t DNLAU0;
    uint32_t DNLAL0;
    uint32_t DCNT0;
    uint32_t DDBS0;

    uint64_t reservedH[7];

    uint32_t DCTL1;
    uint32_t DSTA1;
    uint32_t DCSAU1;
    uint32_t DCSAL1;
    uint32_t DCDAU1;
    uint32_t DCDAL1;
    uint32_t DCLAU1;
    uint32_t DCLAL1;
    uint32_t DSAU1;
    uint32_t DSAL1;
    uint32_t DDAU1;
    uint32_t DDAL1;
    uint32_t DSAT1;
    uint32_t DDAT1;
    uint32_t DNLAU1;
    uint32_t DNLAL1;
    uint32_t DCNT1;
    uint32_t DDBS1;

    uint64_t reservedI[7];

    uint16_t VENI_2;  // DIFFERENT FROM DOCUMENTATION
    uint16_t DEVI_2;  // DIFFERENT FROM DOCUMENTATION
    uint8_t REVID;
    uint8_t GA;
    uint16_t GCTRL;
    uint8_t SEMAPHORE3;
    uint8_t SEMAPHORE2;
    uint8_t SEMAPHORE1;
    uint8_t SEMAPHORE0;
    uint8_t SEMAPHORE7;
    uint8_t SEMAPHORE6;
    uint8_t SEMAPHORE5;
    uint8_t SEMAPHORE4;
    uint32_t MBOX0;
    uint32_t MBOX1;
    uint32_t MBOX2;
    uint32_t MBOX3;

    uint64_t reservedJ[314];
    uint32_t reserved24;

    uint32_t CSRBCR;  
    uint32_t CSRBSR; 
    uint32_t CBAR;


};