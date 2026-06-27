import streamlit as st
import pandas as pd
import json
import os

st.set_page_config(page_title="Estação de Bombeamento")

st.title("Estação de Bombeamento")

# ----------------------------
# Leitura do JSON
# ----------------------------
try:
    with open("../data/leituras.json", "r") as arquivo:
        dados = json.load(arquivo)

    st.subheader("Sensores")

    st.write(f"Nível: {dados['nivel']} %")
    st.write(f"Pressão: {dados['pressao']} bar")
    st.write(f"Vazão: {dados['vazao']} L/min")
    st.write(f"Temperatura: {dados['temperatura']} °C")

    st.subheader("Bombas")

    st.write(f"Bomba 1: {'Ligada' if dados['bomba1'] else 'Desligada'}")
    st.write(f"Bomba 2: {'Ligada' if dados['bomba2'] else 'Desligada'}")

    st.subheader("Alarmes")

    if dados["alarmes"]:
        for alarme in dados["alarmes"]:
            st.write(f"- {alarme}")
    else:
        st.write("Nenhum alarme ativo.")

except FileNotFoundError:
    st.error("Arquivo leituras.json não encontrado.")

# ----------------------------
# Histórico
# ----------------------------
st.subheader("Histórico das Leituras")

try:
    historico = pd.read_csv("../data/historico.csv")
    st.line_chart(historico[["nivel", "temperatura"]])
except:
    st.write("Histórico não disponível.")

# ----------------------------
# Histórico de comandos
# ----------------------------
st.subheader("Histórico de Comandos")

try:
    with open("../data/comandos.txt", "r") as arquivo:
        comandos = arquivo.readlines()

    if comandos:
        for comando in comandos[-10:]:
            st.write(comando.strip())
    else:
        st.write("Nenhum comando registrado.")

except FileNotFoundError:
    st.write("Nenhum comando registrado.")