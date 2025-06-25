# minishell

Una shell minimalista escrita en C como parte del proyecto de la escuela 42.

## 🎯 Objetivo

Recrear una shell similar a **bash** con funcionalidades básicas: ejecución de comandos, pipes, redirecciones, manejo de variables de entorno, y algunos *built-ins*.

## ⚙️ Compilación

```bash
make
```
## 🚀 Uso

```bash
./minishell
```

## 🧠 Funcionalidades

-  Comandos simples
-  Redirecciones: `>`, `<`, `>>`
-  Pipes `|`
-  Punto y coma `;`
-  Variables de entorno (`$HOME`, `$PATH`)
-  Built-ins: `cd`, `echo`, `pwd`, `env`, `export`, `unset`, `exit`
-  Manejo de señales: Ctrl+C, Ctrl+\

## 📁 Estructura del proyecto

```bash
minishell
├── include            # Archivos de cabecera (.h)
├── libft              # Librería personalizada (libft)
├── obj                # Archivos objeto (.o)
├── src                # Código fuente
│   ├── builtin        # Implementación de comandos internos
│   ├── env            # Manejo de variables de entorno
│   ├── executor       # Lógica de ejecución de comandos
│   ├── parser         # Parsing y tokenización de la línea de comandos
│   │   └── validators # Validaciones del input
│   ├── signals        # Manejo de señales del sistema
│   ├── utils          # Funciones auxiliares
│   └── minishell.c    # Entrada principal del programa
├── LICENSE
├── Makefile
└── README.md

```
## 👨‍💻 Autores

- bgil-fer
- sonlira

## 📜 Licencia

Este proyecto está licenciado bajo la [MIT License](./LICENSE)
