/*
 * gpio.c
 *
 * FOR SSS SOFTWARE FALL 2025 TRAINING
 *
 *
 *  Created on: Sep 21, 2025
 *      Author: nithinsenthil
 */

#include "gpio_training.h"

void gpio_high(GPIO_TypeDef *port, int pin) {
	port->ODR |= GPIO_HIGH << pin;
}

void gpio_low(GPIO_TypeDef *port, int pin) {
	port->ODR &= GPIO_LOW << pin;
}

void gpio_set(GPIO_TypeDef *port, int pin, GPIO_VALUE value) {
	port->ODR |= value << pin;
}

void gpio_configureMode(GPIO_TypeDef *port, int pin, GPIO_CNF cnf, GPIO_MODE mode) {
	//port->CRH = (cnf << 21) | (mode << 19);
	port->CRH = cnf << ((pin-7) * 3 + 3) | (mode << ((pin-7) * 3 + 1));

}

/*
 * Pls don't modify cause I will be sad D:
 */
void rcc_enable(RCC_SELECT reg) {
	RCC->APB2ENR |= reg;
}

