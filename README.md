🌦️ Medidor Climático

Projeto de uma estação climática utilizando ESP32 para realizar a leitura de diferentes condições do ambiente e apresentar os dados em um display OLED.

O sistema realiza medições de temperatura, umidade, pressão atmosférica e luminosidade, exibindo as informações no display OLED e no Monitor Serial.

📌 Funcionalidades

🌡️ Medição de temperatura com DHT22

💧 Medição de umidade com DHT22

🌡️ Medição de temperatura com BMP180

🌬️ Medição de pressão atmosférica com BMP180

☀️ Medição de luminosidade com LDR

🖥️ Exibição dos dados em display OLED SSD1306

📟 Exibição das medições no Monitor Serial

🧪 Simulação do circuito utilizando Wokwi

🛠️ Componentes
Componente	Função
ESP32 DevKit V1	Microcontrolador
DHT22	Temperatura e umidade
BMP180	Temperatura e pressão
LDR	Luminosidade
OLED SSD1306	Exibição dos dados
Resistor 10 kΩ	Circuito do DHT22
🔌 Ligações
DHT22
DHT22	ESP32
VCC	3.3V
DATA	GPIO 15
GND	GND
BMP180

O BMP180 utiliza comunicação I²C.

BMP180	ESP32
SDA	GPIO 21
SCL	GPIO 22
VCC	3.3V
GND	GND
OLED SSD1306

O display também utiliza comunicação I²C.

OLED	ESP32
SDA	GPIO 21
SCL	GPIO 22
VCC	3.3V
GND	GND

Endereço I²C utilizado:

0x3C

LDR
LDR	ESP32
AO	GPIO 34
VCC	3.3V
GND	GND

A leitura do LDR é convertida para uma escala de 0 a 100%.

⚙️ Configuração dos pinos
#define DHT_PIN 15
#define I2C_SDA 21
#define I2C_SCL 22
#define LDR_PIN 34

Recurso	GPIO
DHT22	15
I²C SDA	21
I²C SCL	22
LDR	34
📊 Dados exibidos

O display OLED apresenta informações como:

Temp: XX.X C
Umid: XX.X %
Press: XXXX hPa
Luz: XX %


As informações são atualizadas aproximadamente a cada 2 segundos.

💻 Tecnologias

C/C++

Arduino

ESP32

DHT22

BMP180

LDR

OLED SSD1306

Comunicação I²C

Wokwi

📚 Bibliotecas

As bibliotecas utilizadas estão especificadas no arquivo libraries.txt:

Adafruit BMP085 Library

ESP8266 and ESP32 OLED driver for SSD1306 displays

DHT sensor library for ESPx

📁 Estrutura do projeto
MeasureClimate/
│
├── diagram.json
├── libraries.txt
├── sketch.ino
├── wokwi-project.txt
└── README.md

sketch.ino

Arquivo principal contendo a lógica de inicialização dos sensores, leitura dos dados e atualização do display.

diagram.json

Arquivo responsável pela definição do circuito utilizado na simulação do Wokwi.

libraries.txt

Lista das bibliotecas necessárias para o funcionamento do projeto.

wokwi-project.txt

Arquivo relacionado à configuração do projeto no Wokwi.

README.md

Documentação do projeto.

🚀 Como executar
Simulação no Wokwi

Acesse o repositório do projeto.

Abra o projeto no Wokwi através da configuração disponível.

Inicie a simulação.

Observe os valores dos sensores no display OLED e no Monitor Serial.

ESP32 físico

Instale a Arduino IDE.

Configure o suporte para placas ESP32.

Instale as bibliotecas necessárias.

Monte o circuito conforme as ligações descritas neste README.

Abra o arquivo sketch.ino.

Selecione a placa ESP32.

Selecione a porta serial.

Faça o upload do código.

Abra o Monitor Serial em 115200 baud.

🔄 Funcionamento

O funcionamento do sistema pode ser representado da seguinte forma:

                    ┌─────────────┐
                    │    ESP32    │
                    └──────┬──────┘
                           │
          ┌────────────────┼────────────────┐
          │                │                │
          ▼                ▼                ▼
       ┌───────┐        ┌───────┐        ┌─────┐
       │ DHT22 │        │BMP180 │        │ LDR │
       └───┬───┘        └───┬───┘        └──┬──┘
           │                │               │
       ┌───┴───┐        ┌───┴───┐           │
       ▼       ▼        ▼       ▼           ▼
     Temp.   Umid.    Temp.   Pressão    Luz
       │       │        │       │           │
       └───────┴────────┴───────┴───────────┘
                           │
                           ▼
                    ┌────────────┐
                    │ OLED SSD1306│
                    └────────────┘

🎯 Objetivo

O projeto tem como objetivo aplicar conceitos de sistemas embarcados, sensoriamento e Internet das Coisas (IoT) utilizando o ESP32.

Por meio dos sensores, o sistema consegue coletar informações do ambiente e apresentá-las de maneira simples e visual.

🔮 Possíveis melhorias

 Conexão Wi-Fi

 Envio dos dados para uma API

 Armazenamento do histórico das medições

 Dashboard web

 Gráficos de temperatura e umidade

 Sistema de alertas

 Sensor de chuva

 Sensor de vento

 Alimentação por bateria


