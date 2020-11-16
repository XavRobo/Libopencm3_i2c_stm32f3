#include <stdio.h>
#include "clock.h"
#include "motor.h"
#include "encoder.h"
#include "uart.h"
#include "i2c.h"

void test_motor();
void test_send_comm_usart();
void blink_led();
void test_i2c();

int main(){
    
    //setup
    clock_setup();
    //motor_setup();
    //uart_setup();
    //encoder_setup();
    

    //volatile int counterLeft;
    //volatile int counterRight;

    //tests
    // TEST Benano
    /*
    while(1){
    //fprintf(stderr,"coucou sur le debug \n");
    //delay_ms(200);
    // int charReceived = 'a';
    // fscanf(stderr,"%c",&charReceived);
    // fprintf(stderr,"%c",charReceived);
    // test_send_comm_usart();
    // delay_ms(1000);
    //delay_ms(500);
    //test_send_comm_usart();
    //delay_ms(500);
    
    //encoder testing
    encoder_update(ENCODER_A,&counterLeft);
    encoder_update(ENCODER_B,&counterRight);
    fprintf(stderr,"counterLeft=%d \t counterRight=%d \n",counterLeft,counterRight);
    }
    */

    test_i2c();
    

}

void blink_led(){     //led is on PB3     
    _gpio_setup_pin(RCC_GPIOB,GPIOB,GPIO3,GPIO_MODE_OUTPUT);          
    while(1){         
        gpio_toggle(GPIOB,GPIO3);
        delay_ms(250);     
    } 
}

void test_i2c(){
    //SCL
    _gpio_setup_pin_af(RCC_GPIOB, GPIOB,GPIO6, GPIO_AF4);
    //SDA
    _gpio_setup_pin_af(RCC_GPIOB, GPIOB,GPIO7, GPIO_AF4);

    //LED
    _gpio_setup_pin(RCC_GPIOB,GPIOB,GPIO3,GPIO_MODE_OUTPUT);     

    i2c_setup();
    uint8_t msg = 0xab;
    uint8_t* read;

    while(1){
        gpio_toggle(GPIOB,GPIO3);
        i2c_transfer7(I2C1, 0x52<<1, &msg, sizeof(msg), read, 0);
        delay_ms(1000);
	}
}

void test_motor(){
    motor_set(MOTOR_A,-70);
    motor_set(MOTOR_B,-45);
}


void test_send_comm_usart(){
  uint16_t myInt = 20;
  fprintf(stderr,"sending a int: %d \n",myInt);
  //usart_send_blocking(COMM_USART,myInt);
  fprintf(stdout,"%d",myInt);
  // fprintf(stderr,"sending a string : hello\n");
  // fprintf(stdout,"hello"); 

}
        
