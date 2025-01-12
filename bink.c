#include <stdio.h>
#include "pico/stdlib.h"

// Definindo o pino do LED
const uint LED_PIN = 13;

// Função para enviar um ponto (.)
void send_dot() {
    gpio_put(LED_PIN, 1); // Acende o LED
    sleep_ms(200);        // Espera 0,2 segundos
    gpio_put(LED_PIN, 0); // Apaga o LED
    sleep_ms(125);        // Espera 0,125 segundos (GAP)
}

// Função para enviar um traço (-)
void send_dash() {
    gpio_put(LED_PIN, 1); // Acende o LED
    sleep_ms(800);        // Espera 0,8 segundos
    gpio_put(LED_PIN, 0); // Apaga o LED
    sleep_ms(125);        // Espera 0,125 segundos (GAP)
}

// Função para enviar o sinal SOS
void send_sos() {
    // Envia três pontos
    for (int i = 0; i < 3; i++) {
        send_dot();
    }
    sleep_ms(250); // Espera 0,25 segundos entre letras

    // Envia três traços
    for (int i = 0; i < 3; i++) {
        send_dash();
    }
    sleep_ms(250); // Espera 0,25 segundos entre letras

    // Envia três pontos
    for (int i = 0; i < 3; i++) {
        send_dot();
    }
}

int main() {
    // Inicializa o GPIO do LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        send_sos(); // Envia o sinal SOS
        sleep_ms(3000); // Espera 3 segundos antes de reiniciar o ciclo
    }

    return 0;
}