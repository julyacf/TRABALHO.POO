import streamlit as st
import json

with open("../data/leituras.json", "r") as arquivo:
    dados = json.load(arquivo)

st.title("🚰 Estação de Bombeamento")

st.subheader("Sensores")

st.write(f"**Nível:** {dados['nivel']} %")
st.write(f"**Pressão:** {dados['pressao']} bar")
st.write(f"**Vazão:** {dados['vazao']} L/min")
st.write(f"**Temperatura:** {dados['temperatura']} °C")

st.subheader("Bombas")

st.write(f"Bomba 1: {'🟢 Ligada' if dados['bomba1'] else '🔴 Desligada'}")
st.write(f"Bomba 2: {'🟢 Ligada' if dados['bomba2'] else '🔴 Desligada'}")

st.subheader("Alarmes")

if len(dados["alarmes"]) == 0:
    st.success("Nenhum alarme ativo.")
else:
    for alarme in dados["alarmes"]:
        st.error(alarme)