#include "pico/stdlib.h"
#include "hardware/timer.h"
#include <stdio.h>
#include <stdbool.h>

#define LED_VERMELHO 13
#define LED_AZUL 12
#define LED_VERDE 11
#define BOTAO 5

volatile bool botao_pressionado = false;
volatile bool rotina_em_execucao = false;
static int estado = 0;

// Função de debounce para o botão
bool debounce() {
    static uint32_t ultimo_tempo = 0;
    uint32_t tempo_atual = to_ms_since_boot(get_absolute_time());

    if ((tempo_atual - ultimo_tempo) > 200) { // Debounce de 200ms
        ultimo_tempo = tempo_atual;
        return true;
    }
    return false;
}

// Callback para desligar LEDs progressivamente
bool turn_off_callback(struct repeating_timer *t) {

    switch (estado) {
        case 1:
            gpio_put(LED_VERDE, false);
            estado++;
            break;
        case 2:
            gpio_put(LED_AZUL, false);
            estado++;
            break;
        case 3:
            gpio_put(LED_VERMELHO, false);
            rotina_em_execucao = false;
            estado = 0;
            return false; // Para de repetir
    }
    return true;
}

void inicia_sequencia_leds() {
    if (!rotina_em_execucao) {
        rotina_em_execucao = true;
        struct repeating_timer timer;

        gpio_put(LED_VERMELHO, true);
        gpio_put(LED_AZUL, true);
        gpio_put(LED_VERDE, true);
        estado++;

        add_repeating_timer_ms(3000, turn_off_callback, NULL, &timer);
    }
}

int main() {
    stdio_init_all();

    gpio_init(LED_VERMELHO);
    gpio_init(LED_AZUL);
    gpio_init(LED_VERDE);
    gpio_init(BOTAO);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    while (true) {
        if (!gpio_get(BOTAO) && debounce()) { // Botão pressionado
            if (!rotina_em_execucao) {
                inicia_sequencia_leds();
            }
        }
        sleep_ms(10); // Pequena pausa para evitar processamento excessivo
    }

    return 0;
}
