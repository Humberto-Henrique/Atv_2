Temporizador de um Disparo (One Shot) com Raspberry Pi Pico
Este projeto implementa um sistema de temporização para o acionamento de LEDs utilizando a função add_alarm_in_ms() do Pico SDK. O sistema é acionado através do clique de um botão (pushbutton), e os LEDs mudam de estado a cada 3 segundos, de acordo com a sequência descrita.

Objetivo
O objetivo deste projeto é implementar um sistema de temporização baseado no acionamento de LEDs utilizando a função de alarme do Pico SDK. Ao pressionar o botão, os LEDs são acesos em sequência, começando com todos os LEDs ligados, depois dois LEDs ligados, e finalmente um LED ligado. O temporizador tem um atraso de 3 segundos entre cada mudança de estado.

Requisitos
Hardware:
Microcontrolador: Raspberry Pi Pico W
LEDs: 3 LEDs (azul, vermelho e verde)
Resistores: 3 resistores de 330 Ω
Botão: Pushbutton (para acionar a sequência de LEDs)
Software:
Pico SDK (com suporte para funções de temporização)
Ambiente de desenvolvimento com suporte ao C e ao Pico SDK
Ferramenta Educacional BitDogLab para experimentação com o LED RGB (GPIOs 11, 12, 13) e o botão A (GPIO 05)
Fluxograma de Atuação
A operação do sistema segue o fluxograma simplificado:

Botão Pressionado: Quando o botão é pressionado, todos os LEDs (azul, vermelho e verde) são acesos.
Sequência de LEDs: Após 3 segundos, dois LEDs são desligados, e após mais 3 segundos, apenas um LED permanece ligado.
O ciclo é realizado uma vez por clique no botão e não pode ser reiniciado até que todos os LEDs tenham sido desligados.
Funcionalidade do Temporizador
Atraso de 3 segundos: A mudança de estado dos LEDs ocorre a cada 3 segundos (3000ms).
Funções de Call-Back: A mudança de estado dos LEDs é gerenciada por funções de call-back que são chamadas pelo alarme.#   A t v _ 2  
 