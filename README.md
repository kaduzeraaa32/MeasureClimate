<h1 align="center">🌦️ Medidor Climático — ESP32</h1>

<p align="center">
  <strong>Estação climática para monitoramento de condições ambientais utilizando ESP32.</strong>
</p>

<p align="center">
  🌡️ Temperatura &nbsp;•&nbsp;
  💧 Umidade &nbsp;•&nbsp;
  🌬️ Pressão &nbsp;•&nbsp;
  ☀️ Luminosidade
</p>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-Embedded-blue?style=for-the-badge&logo=espressif" alt="ESP32">
  <img src="https://img.shields.io/badge/C%2FC%2B%2B-Arduino-orange?style=for-the-badge&logo=cplusplus" alt="C/C++">
  <img src="https://img.shields.io/badge/Wokwi-Simulation-purple?style=for-the-badge" alt="Wokwi">
  <img src="https://img.shields.io/badge/IoT-Project-green?style=for-the-badge" alt="IoT">
</p>

---

<h2 align="center">📖 Sobre o Projeto</h2>

<p align="center">
  O <strong>Medidor Climático</strong> é um projeto de sistemas embarcados desenvolvido
  utilizando um ESP32 para realizar o monitoramento de diferentes condições do ambiente.
</p>

<p align="center">
  O sistema utiliza sensores para coletar informações de
  <strong>temperatura, umidade, pressão atmosférica e luminosidade</strong>.
  Os dados são processados pelo ESP32 e apresentados em um
  <strong>display OLED SSD1306</strong> e também no <strong>Monitor Serial</strong>.
</p>

<p align="center">
  O projeto pode ser executado tanto em um <strong>ESP32 físico</strong>
  quanto através de uma <strong>simulação no Wokwi</strong>.
</p>

---

<h2 align="center">✨ Funcionalidades</h2>

<div align="center">

| Recurso | Descrição                          |
| :-----: | :--------------------------------- |
|   🌡️   | Medição de temperatura             |
|    💧   | Medição de umidade                 |
|   🌬️   | Medição de pressão atmosférica     |
|    ☀️   | Medição de luminosidade            |
|   🖥️   | Exibição dos dados no OLED         |
|    📟   | Exibição no Monitor Serial         |
|    🔄   | Atualização periódica das medições |
|    📡   | Comunicação I²C                    |
|    🧪   | Simulação através do Wokwi         |

</div>

---

<h2 align="center">🛠️ Componentes</h2>

<div align="center">

|     Componente     | Quantidade | Função                            |
| :----------------: | :--------: | :-------------------------------- |
| 🔵 ESP32 DevKit V1 |      1     | Microcontrolador principal        |
|      🌡️ DHT22     |      1     | Temperatura e umidade             |
|     🌬️ BMP180     |      1     | Temperatura e pressão atmosférica |
|       ☀️ LDR       |      1     | Medição da luminosidade           |
|  🖥️ OLED SSD1306  |      1     | Exibição das informações          |
|  🔩 Resistor 10 kΩ |      1     | Pull-up do DHT22                  |
|     🔌 Jumpers     |      —     | Conexões do circuito              |

</div>

---

<h2 align="center">🔌 Ligações e Conexões</h2>

<h3 align="center">🌡️ DHT22 — Temperatura e Umidade</h3>

<p align="center">
  O DHT22 é responsável pela leitura da temperatura e da umidade do ambiente.
</p>

<div align="center">

| DHT22 |  ESP32  |
| :---: | :-----: |
|  VCC  |   3.3V  |
|  DATA | GPIO 15 |
|  GND  |   GND   |

</div>

```cpp
#define DHT_PIN 15
```

---

<h3 align="center">🌬️ BMP180 — Pressão Atmosférica</h3>

<p align="center">
  O BMP180 utiliza comunicação <strong>I²C</strong> para transmitir os dados ao ESP32.
</p>

<div align="center">

| BMP180 |  ESP32  |
| :----: | :-----: |
|   VCC  |   3.3V  |
|   SDA  | GPIO 21 |
|   SCL  | GPIO 22 |
|   GND  |   GND   |

</div>

<p align="center">

O BMP180 fornece:

<br>

🌡️ Temperatura
🌬️ Pressão atmosférica

</p>

---

<h3 align="center">🖥️ OLED SSD1306 — Display</h3>

<p align="center">
  O display OLED utiliza o mesmo barramento <strong>I²C</strong> utilizado pelo BMP180.
</p>

<div align="center">

| OLED |  ESP32  |
| :--: | :-----: |
|  VCC |   3.3V  |
|  SDA | GPIO 21 |
|  SCL | GPIO 22 |
|  GND |   GND   |

</div>

<h4 align="center">📡 Endereço I²C</h4>

<p align="center">

```text
0x3C
```

</p>

```cpp
#define I2C_SDA 21
#define I2C_SCL 22
```

<p align="center">
  💡 O BMP180 e o OLED podem compartilhar os mesmos pinos SDA e SCL,
  pois cada dispositivo possui um endereço diferente no barramento I²C.
</p>

---

<h3 align="center">☀️ LDR — Luminosidade</h3>

<p align="center">
  O LDR realiza uma leitura analógica da intensidade luminosa presente no ambiente.
</p>

<div align="center">

| LDR |  ESP32  |
| :-: | :-----: |
|  AO | GPIO 34 |
| VCC |   3.3V  |
| GND |   GND   |

</div>

<p align="center">
  A leitura do LDR é convertida para uma escala aproximada de <strong>0% a 100%</strong>.
</p>

```cpp
#define LDR_PIN 34
```

---

<h2 align="center">📍 Configuração dos Pinos</h2>

<div align="center">

|   Recurso  |  GPIO  |
| :--------: | :----: |
|  🌡️ DHT22 | **15** |
| 📡 I²C SDA | **21** |
| 📡 I²C SCL | **22** |
|   ☀️ LDR   | **34** |

</div>

### ⚙️ Definições utilizadas

```cpp
#define DHT_PIN 15
#define I2C_SDA 21
#define I2C_SCL 22
#define LDR_PIN 34
```

---

<h2 align="center">📊 Dados Exibidos</h2>

<p align="center">
  O display OLED apresenta as principais informações coletadas pelos sensores.
</p>

<div align="center">

```text
┌────────────────────┐
│   MEDIDOR CLIMA    │
├────────────────────┤
│ Temp:  25.4 °C     │
│ Umid:  62.3 %      │
│ Press: 1013 hPa    │
│ Luz:   74 %        │
└────────────────────┘
```

</div>

<p align="center">
  As informações são atualizadas aproximadamente a cada <strong>2 segundos</strong>.
</p>

---

<h3 align="center">📟 Monitor Serial</h3>

<p align="center">
  As medições também são enviadas para o Monitor Serial para facilitar
  testes, acompanhamento e depuração do sistema.
</p>

```text
========================
     MEDIDOR CLIMÁTICO
========================
Temperatura: 25.4 °C
Umidade:     62.3 %
Pressão:     1013 hPa
Luminosidade: 74 %
========================
```

---

<h2 align="center">⚙️ Funcionamento do Sistema</h2>

<p align="center">
  O ESP32 atua como o controlador central do projeto.
  Ele recebe os dados dos sensores, processa as informações
  e apresenta os resultados no OLED e no Monitor Serial.
</p>

<div align="center">

```text
                    ┌─────────────────┐
                    │      ESP32      │
                    │   Controlador   │
                    └────────┬────────┘
                             │
          ┌──────────────────┼──────────────────┐
          │                  │                  │
          ▼                  ▼                  ▼
     ┌─────────┐        ┌─────────┐        ┌─────────┐
     │  DHT22  │        │ BMP180  │        │   LDR   │
     └────┬────┘        └────┬────┘        └────┬────┘
          │                  │                  │
      ┌───┴───┐          ┌───┴───┐              │
      ▼       ▼          ▼       ▼              ▼
    Temp.  Umidade     Temp.   Pressão      Luminosidade
      │       │          │       │              │
      └───────┴──────────┴───────┴──────────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │   Processamento │
                    │      ESP32      │
                    └────────┬────────┘
                             │
                    ┌────────┴────────┐
                    ▼                 ▼
              ┌───────────┐     ┌──────────────┐
              │    OLED   │     │    Serial    │
              │  SSD1306  │     │    Monitor   │
              └───────────┘     └──────────────┘
```

</div>

---

<h2 align="center">🔄 Fluxo de Funcionamento</h2>

<div align="center">

```text
              🚀 INÍCIO
                  │
                  ▼
       Inicialização do ESP32
                  │
                  ▼
        Inicialização dos sensores
                  │
                  ▼
        Inicialização do OLED
                  │
                  ▼
       ┌────────────────────┐
       │ Realizar as leituras│
       └──────────┬─────────┘
                  │
          ┌───────┼────────┐
          ▼       ▼        ▼
       🌡️ Temp.  💧 Umid.  ☀️ Luz
                  │
                  ▼
             🌬️ Pressão
                  │
                  ▼
        Processar os valores
                  │
             ┌────┴────┐
             ▼         ▼
           OLED      Serial
             │         │
             └────┬────┘
                  ▼
             Aguardar ~2s
                  │
                  └──────► Repetir
```

</div>

---

<h2 align="center">💻 Tecnologias Utilizadas</h2>

<div align="center">

|  Tecnologia | Utilização                     |
| :---------: | :----------------------------- |
|  **C/C++**  | Desenvolvimento do código      |
| **Arduino** | Framework de desenvolvimento   |
|  **ESP32**  | Microcontrolador               |
|  **DHT22**  | Temperatura e umidade          |
|  **BMP180** | Temperatura e pressão          |
|   **LDR**   | Luminosidade                   |
| **SSD1306** | Display OLED                   |
|   **I²C**   | Comunicação entre dispositivos |
|  **Wokwi**  | Simulação do circuito          |

</div>

---

<h2 align="center">📚 Bibliotecas</h2>

<p align="center">
  As bibliotecas utilizadas estão especificadas no arquivo
  <code>libraries.txt</code>.
</p>

```text
Adafruit BMP085 Library
ESP8266 and ESP32 OLED driver for SSD1306 displays
DHT sensor library for ESPx
```

---

<h2 align="center">📁 Estrutura do Projeto</h2>

```text
MeasureClimate/
│
├── 📄 diagram.json
├── 📄 libraries.txt
├── 📄 sketch.ino
├── 📄 wokwi-project.txt
└── 📄 README.md
```

---

<h3 align="center">📄 sketch.ino</h3>

<p align="center">
  Arquivo principal contendo a lógica do projeto.
</p>

<p align="center">

• Inicialização dos sensores
• Configuração dos pinos
• Leitura dos sensores
• Processamento dos dados
• Atualização do OLED
• Comunicação com o Monitor Serial

</p>

---

<h3 align="center">📄 diagram.json</h3>

<p align="center">
  Define os componentes e as conexões utilizadas durante
  a simulação do circuito no Wokwi.
</p>

---

<h3 align="center">📄 libraries.txt</h3>

<p align="center">
  Contém a lista de bibliotecas necessárias para executar o projeto.
</p>

---

<h3 align="center">📄 wokwi-project.txt</h3>

<p align="center">
  Arquivo relacionado às configurações utilizadas pelo projeto no Wokwi.
</p>

---

<h3 align="center">📄 README.md</h3>

<p align="center">
  Documentação e informações sobre o projeto.
</p>

---

<h2 align="center">🧪 Simulação no Wokwi</h2>

<p align="center">
  O projeto pode ser executado virtualmente utilizando o
  <strong>Wokwi</strong>, permitindo testar o circuito sem a necessidade
  de possuir fisicamente todos os componentes.
</p>

<h3 align="center">▶️ Como executar</h3>

<div align="center">

1. Abra o projeto no Wokwi.
2. Verifique as conexões do circuito.
3. Inicie a simulação.
4. Observe os valores no display OLED.
5. Abra o Monitor Serial.
6. Acompanhe as medições dos sensores.

</div>

---

<h2 align="center">🚀 Como Executar no ESP32</h2>

<h3 align="center">1️⃣ Instalar a Arduino IDE</h3>

<p align="center">
  Instale a Arduino IDE em seu computador.
</p>

<h3 align="center">2️⃣ Configurar o ESP32</h3>

<p align="center">
  Adicione o suporte às placas ESP32 na Arduino IDE.
</p>

<h3 align="center">3️⃣ Instalar as bibliotecas</h3>

<p align="center">
  Instale as bibliotecas utilizadas pelo projeto.
</p>

<h3 align="center">4️⃣ Montar o circuito</h3>

<p align="center">
  Monte o circuito seguindo as ligações apresentadas neste README.
</p>

<h3 align="center">5️⃣ Abrir o código</h3>

```text
sketch.ino
```

<h3 align="center">6️⃣ Selecionar a placa</h3>

<p align="center">
  Selecione a placa ESP32 correspondente ao seu dispositivo.
</p>

<h3 align="center">7️⃣ Selecionar a porta</h3>

<p align="center">
  Selecione a porta serial onde o ESP32 está conectado.
</p>

<h3 align="center">8️⃣ Fazer o upload</h3>

<p align="center">
  Envie o programa para o ESP32.
</p>

<h3 align="center">9️⃣ Abrir o Monitor Serial</h3>

<p align="center">
  Configure a velocidade da comunicação para:
</p>

```text
115200 baud
```

---

<h2 align="center">📈 Dados Coletados</h2>

<h3 align="center">🌡️ Temperatura</h3>

<p align="center">
  A temperatura é obtida através do DHT22 e também do BMP180.
</p>

<h3 align="center">💧 Umidade</h3>

<p align="center">
  A umidade relativa do ar é medida através do DHT22.
</p>

<h3 align="center">🌬️ Pressão Atmosférica</h3>

<p align="center">
  A pressão atmosférica é medida pelo BMP180 e apresentada em <strong>hPa</strong>.
</p>

<h3 align="center">☀️ Luminosidade</h3>

<p align="center">
  A luminosidade é obtida através do LDR e convertida para uma escala percentual.
</p>

---

<h2 align="center">🎯 Objetivo do Projeto</h2>

<p align="center">
  O principal objetivo é aplicar conhecimentos de
  <strong>sistemas embarcados, sensoriamento e Internet das Coisas (IoT)</strong>
  utilizando o ESP32.
</p>

<p align="center">
  O projeto também permite praticar programação em C/C++,
  comunicação I²C, leitura de sensores e apresentação de dados.
</p>

---

<h2 align="center">🔮 Possíveis Melhorias</h2>

<h3 align="center">📡 Conectividade</h3>

<div align="center">

* [ ] Conexão Wi-Fi
* [ ] Bluetooth
* [ ] Envio dos dados para uma API
* [ ] Integração com MQTT

</div>

<h3 align="center">☁️ Armazenamento</h3>

<div align="center">

* [ ] Banco de dados
* [ ] Histórico das medições
* [ ] Armazenamento em nuvem
* [ ] Integração com Supabase

</div>

<h3 align="center">📊 Visualização</h3>

<div align="center">

* [ ] Dashboard web
* [ ] Gráficos de temperatura
* [ ] Gráficos de umidade
* [ ] Histórico de pressão
* [ ] Monitoramento em tempo real

</div>

<h3 align="center">🚨 Automação</h3>

<div align="center">

* [ ] Sistema de alertas
* [ ] Notificações
* [ ] Limites configuráveis
* [ ] Acionamento de dispositivos externos

</div>

<h3 align="center">🌧️ Novos Sensores</h3>

<div align="center">

* [ ] Sensor de chuva
* [ ] Sensor de velocidade do vento
* [ ] Sensor de qualidade do ar
* [ ] Sensor de CO₂

</div>

<h3 align="center">🔋 Energia</h3>

<div align="center">

* [ ] Alimentação por bateria
* [ ] Monitoramento do nível da bateria
* [ ] Modo de baixo consumo
* [ ] Alimentação solar

</div>

---

<h2 align="center">🌐 Arquitetura Futura</h2>

<p align="center">
  Uma possível evolução do projeto é conectar o ESP32 à internet,
  permitindo armazenar e visualizar as informações remotamente.
</p>

<div align="center">

```text
┌─────────────────┐
│     Sensores    │
│ 🌡️ 💧 🌬️ ☀️    │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│      ESP32      │
└────────┬────────┘
         │
       Wi-Fi
         │
         ▼
┌─────────────────┐
│       API       │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│    Banco de     │
│      Dados      │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│    Dashboard    │
│       Web       │
└─────────────────┘
```

</div>

<p align="center">
  Dessa forma, o projeto poderia evoluir de um simples medidor local
  para uma plataforma completa de <strong>monitoramento climático IoT</strong>.
</p>

---

<h2 align="center">📌 Resumo</h2>

<p align="center">
  O <strong>Medidor Climático</strong> utiliza um ESP32 para coletar
  informações ambientais através de diferentes sensores e apresentar
  os resultados de forma simples e visual.
</p>

<div align="center">

🌡️ Temperatura
💧 Umidade
🌬️ Pressão atmosférica
☀️ Luminosidade

⬇️

🔵 **ESP32**

⬇️

🖥️ **OLED SSD1306**   |   📟 **Monitor Serial**

</div>

---

<h2 align="center">👨‍💻 Projeto</h2>

<p align="center">
  <strong>Medidor Climático — ESP32</strong>
</p>

<p align="center">
  C/C++ • Arduino • ESP32 • IoT • Sensores • Sistemas Embarcados
</p>

<p align="center">
  🌦️ <strong>Monitorando o ambiente através da tecnologia.</strong> 🌦️
</p>

---

<p align="center">
  ⭐ Se este projeto foi útil para você, considere deixar uma estrela no repositório!
</p>
