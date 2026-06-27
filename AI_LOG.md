# AI_LOG

## Registro 1

**Data:** 27/06/2026

**Ferramenta:** ChatGPT

**Pedido:**
Auxiliar na implementação do padrão Repository e revisar a arquitetura do projeto.

**Aceito:**
- Implementação da classe Repository.
- Organização da persistência em uma única classe.

**Rejeitado:**
- Refatoração completa do projeto para usar `vector<Sensor*>`.

**Justificativa:**
A equipe optou por manter a arquitetura estável para evitar quebrar um projeto já funcional.

---

## Registro 2

**Data:** 27/06/2026

**Ferramenta:** ChatGPT

**Pedido:**
Revisar README e documentação do projeto.

**Aceito:**
- Sugestões para organização do README.
- Descrição do padrão Repository.

**Rejeitado:**
- Modelo inicial de README incompleto.

**Justificativa:**
Foi necessário adequar a documentação aos requisitos da especificação da disciplina.

---

## Registro 3

**Data:** 27/06/2026

**Ferramenta:** ChatGPT

**Pedido:**
Auxiliar na implementação de tratamento de exceções.

**Aceito:**
- Verificação de abertura dos arquivos com `is_open()`.
- Uso de `runtime_error`.

**Rejeitado:**
- Alterações grandes na arquitetura que poderiam comprometer a estabilidade do projeto.

**Justificativa:**
Foi priorizado manter o sistema funcionando e atender aos requisitos obrigatórios.