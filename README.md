# Temporizador de um Disparo (One Shot) com Raspberry Pi Pico

Este projeto implementa um sistema de temporização para o acionamento de LEDs utilizando a função `add_alarm_in_ms()` do **Pico SDK**. O sistema é acionado através do clique de um botão (pushbutton), e os LEDs mudam de estado a cada 3 segundos, de acordo com a sequência descrita.

## Objetivo

O objetivo deste projeto é implementar um sistema de temporização baseado no acionamento de LEDs utilizando a função de alarme do **Pico SDK**. Ao pressionar o botão, os LEDs são acesos em sequência: começando com todos os LEDs ligados, depois dois LEDs ligados, e finalmente um LED ligado. O temporizador tem um atraso de 3 segundos entre cada mudança de estado.

## Requisitos

### Hardware

- **Microcontrolador**: Raspberry Pi Pico W
- **LEDs**: 3 LEDs (azul, vermelho e verde)
- **Resistores**: 3 resistores de 330 Ω
- **Botão**: Pushbutton (para acionar a sequência de LEDs)

### Software

- **Pico SDK** (com suporte para funções de temporização)
- **Ambiente de desenvolvimento** com suporte ao C e ao Pico SDK
- **Ferramenta Educacional BitDogLab** para experimentação com o LED RGB (GPIOs 11, 12, 13) e o botão A (GPIO 05)

## Fluxograma de Atuação

A operação do sistema segue o fluxograma simplificado abaixo:

1. **Botão Pressionado**: Quando o botão é pressionado, todos os LEDs (azul, vermelho e verde) são acesos.
2. **Sequência de LEDs**: 
    - Após 3 segundos, dois LEDs são desligados.
    - Após mais 3 segundos, apenas um LED permanece ligado.
3. O ciclo é realizado uma vez por clique no botão e não pode ser reiniciado até que todos os LEDs tenham sido desligados.

## Funcionalidade do Temporizador

- **Atraso de 3 segundos**: A mudança de estado dos LEDs ocorre a cada 3 segundos (3000ms).
- **Funções de Call-Back**: A mudança de estado dos LEDs é gerenciada por funções de call-back que são chamadas pelo alarme.

## Configuração do Hardware

O código utiliza os pinos GPIO 11, 12 e 13 do Raspberry Pi Pico para controlar os LEDs e o pino GPIO 5 para o botão:

- **LED Azul**: GPIO 12
- **LED Vermelho**: GPIO 13
- **LED Verde**: GPIO 11
- **Botão**: GPIO 5

## Fluxo do Código

1. **Inicialização dos LEDs e do Botão**: Inicializamos os pinos dos LEDs como saídas e o pino do botão como entrada.
2. **Configuração do Alarme**: Usamos a função `add_alarm_in_ms()` para acionar as mudanças de estado dos LEDs a cada 3 segundos.
3. **Sequência de LEDs**: A cada execução do alarme, alteramos o estado dos LEDs de acordo com a sequência.
4. **Finalização do Ciclo**: O ciclo se repete uma vez por clique do botão e não pode ser reiniciado até que todos os LEDs tenham sido desligados.

