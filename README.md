# Sistema de Estação de Bombeamento

## Descrição

Este projeto simula uma estação de bombeamento de água utilizando Programação Orientada a Objetos em C++. O sistema realiza a leitura de sensores, controla bombas, gera alarmes e armazena os dados em arquivos JSON e CSV. Um supervisor desenvolvido em Streamlit permite visualizar as informações do sistema.

---

## Arquitetura

O sistema é dividido em duas camadas:

### Dispositivo (C++)

Responsável por:

- Simulação dos sensores
- Controle das bombas
- Aplicação das regras operacionais
- Geração de alarmes
- Persistência dos dados

### Supervisor (Python + Streamlit)

Responsável por:

- Leitura do arquivo JSON gerado pelo dispositivo
- Exibição dos dados operacionais
- Exibição do estado das bombas
- Exibição dos alarmes ativos

---

## Estrutura do Projeto

text
TrabalhoPOO/
├── dispositivo_cpp/
├── supervisor_phyton/
├── data/
├── README.md
├── AI_LOG.md
└── planejamento.md


---

## Funcionalidades

- Leitura de sensores de nível, pressão, vazão e temperatura
- Controle de duas bombas
- Geração de alarmes operacionais
- Histórico de leituras em CSV
- Estado atual em JSON
- Registro de comandos executados
- Simulação de falha de sensor
- Alternância automática da bomba principal

---

## Assinatura Operacional da Dupla

*Identificador da estação:* 25

### Limites Operacionais

- Nível baixo: 25%
- Nível alto: 85%
- Pressão alta: 7.5 bar
- Temperatura alta: 65 °C

### Falha Simulada

- Falha aleatória do sensor de nível.

### Regra Específica da Dupla

- Alternância automática da bomba principal a cada 10 ciclos de atualização dos sensores.

---

## Programação Orientada a Objetos

### Encapsulamento

As classes encapsulam seus atributos e disponibilizam acesso através de métodos públicos.

### Herança

Todos os sensores herdam da classe abstrata Sensor.

### Polimorfismo

Os sensores são manipulados através de ponteiros para a classe base utilizando:

cpp
vector<Sensor*>


### Composição

A classe EstacaoBombeamento é composta por sensores, bombas e alarmes.

### Coleções

Utilização de vector para armazenamento e gerenciamento de objetos.

---

## Padrões de Projeto

### Repository

Centraliza toda a persistência de dados do sistema, sendo responsável pela escrita dos arquivos:

- CSV
- JSON
- Histórico de comandos

---

## Diagrama de Classes

text
Sensor (abstrata)
├── SensorNivel
├── SensorPressao
├── SensorVazao
└── SensorTemperatura

EstacaoBombeamento
├── Bomba
├── Alarme
├── vector<Sensor*>
└── Repository

Repository
├── salvarHistorico()
├── salvarJson()
└── salvarComando()


---

## Contrato JSON

O arquivo leituras.json representa o estado atual da estação de bombeamento.

### Estrutura

| Campo | Tipo | Descrição |
|---------|---------|---------|
| nivel | inteiro | Nível do reservatório (%) |
| pressao | número | Pressão do sistema (bar) |
| vazao | número | Vazão (L/min) |
| temperatura | número | Temperatura (°C) |
| bomba1 | boolean | Estado da bomba 1 |
| bomba2 | boolean | Estado da bomba 2 |
| alarmes | array | Lista de alarmes ativos |

### Exemplo

json
{
  "nivel": 47,
  "pressao": 4,
  "vazao": 29,
  "temperatura": 38,
  "bomba1": false,
  "bomba2": true,
  "alarmes": []
}


---

## Como Compilar

bash
cd dispositivo_cpp
g++ *.cpp -o projeto
./projeto


---

## Como Executar o Supervisor

bash
cd supervisor_phyton
streamlit run app.py


---

## Testes Realizados
 
### Teste 1
Atualização dos sensores e geração de leituras.

### Teste 2
Verificação do alarme de nível baixo.

### Teste 3
Verificação do alarme de nível alto.

### Teste 4
Verificação do bloqueio da bomba 2 por alta pressão.

### Teste 5
Verificação do alarme de temperatura alta.

### Teste 6
Verificação da falha simulada do sensor de nível.

### Teste 7
Verificação da alternância automática das bombas após 10 ciclos.

---

## Divisão de Responsabilidades

### Julya Freitas

- Implementação do dispositivo em C++
- Sensores
- Bombas
- Alarmes
- Persistência de dados

### Isaac Poleze

- Supervisor em Streamlit
- Integração com JSON
- Testes
- Documentação

### Ambos

- Modelagem do sistema
- Revisão do código
- README
- AI_LOG
- Apresentação

---

## Limitações Conhecidas

- Sensores simulados por valores aleatórios.
- Comunicação entre dispositivo e supervisor realizada através de arquivos locais.
- Não utiliza comunicação em rede em tempo real.

---

## Integrantes

- Julya Freitas
- Isaac Poleze