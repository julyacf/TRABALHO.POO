# Sistema de Estação de Bombeamento

## Descrição

Este projeto simula uma estação de bombeamento de água utilizando Programação Orientada a Objetos em C++. O sistema realiza a leitura de sensores, controla bombas, gera alarmes e armazena os dados em arquivos JSON e CSV. Um supervisor em Streamlit permite visualizar as informações.

---

## Estrutura do projeto

- `dispositivo_cpp/` → aplicação principal em C++
- `supervisor_python/` → interface em Streamlit
- `data/` → arquivos JSON, CSV e comandos

---

## Funcionalidades

- Leitura de sensores
- Controle de duas bombas
- Geração de alarmes
- Histórico em CSV
- Estado atual em JSON
- Registro de comandos

---

## Programação Orientada a Objetos

### Encapsulamento

Classes como `Bomba` e `Alarme` encapsulam seus atributos.

### Herança

Todos os sensores herdam da classe abstrata `Sensor`.

### Polimorfismo

As classes derivadas implementam o método virtual `ler()`.

---

## Padrões de Projeto

### Repository

Centraliza toda a persistência de dados do sistema, sendo responsável pela escrita dos arquivos CSV, JSON e comandos.

---

## Como compilar

```bash
cd dispositivo_cpp
g++ *.cpp -o projeto
./projeto
```

---

## Como executar o supervisor

```bash
cd supervisor_python
streamlit run app.py
```

---

## Integrantes

- Julya Freitas
- Isaac Poleze