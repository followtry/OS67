#include <sys.h>
void delay(){   // lol, we have no sleep()
    int i = 0;
    for (i = 0; i < 1000000; i++){
        i++;
        i--;
    }
}

int osmain(void)
{
    vga_init();
    gdt_init();
    puts("GDT installed...\n\r\0");
    idt_init();
    puts("IDT installed...\n\r\0");
    isrs_init();
    puts("ISRs installed...\n\r\0");
    irq_init();
    puts("IRQs installed...\n\r\0");

    setcolor(COL_D_GREY, COL_CYAN);
    puts("Welcome to OS67...\n\r\0");
    setcolor(COL_L_GREY, COL_BLACK);

    //timer_init(); 
    kb_init();
    sti();
    for (;;);
    int i;
    for (i = 0; i < 26; i++){
        putchar('A' + i);
        putchar('\n');
        delay();
    }
    return 0;
}
