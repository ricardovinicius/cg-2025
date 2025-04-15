# ⚽ Soccer Game

Um mini-jogo de futebol 2D feito em C usando OpenGL + GLUT, com cenas para menu e gameplay. O objetivo é marcar gols enquanto o tempo está rodando.

---

## 🎮 Funcionalidades

- Menu inicial com título e instrução para começar o jogo
- Cena principal com times esquerdo e direito
- Bola com movimentação e colisão com jogadores e campo
- Gols com placar atualizado automaticamente
- Contador de tempo regressivo
- HUD exibindo placar e tempo
- Troca de cenas (menu → jogo)

---

## 🛠️ Tecnologias

- **Linguagem:** C
- **Gráficos:** OpenGL (GLUT)
- **Compilação:** `make`

---

## 🚀 Como Compilar

### Pré-requisitos

- Linux ou WSL
- `gcc`, `make`
- Bibliotecas OpenGL instaladas:
    - `libgl1-mesa-dev`
    - `freeglut3-dev`

### Compilando com Make

```
make
./main
```

## 🎮 Controles

X: iniciar o jogo a partir do menu

WASD: mover a bola

O tempo e placar são atualizados automaticamente

## 📜 Licença

Este projeto é livre para fins educacionais.