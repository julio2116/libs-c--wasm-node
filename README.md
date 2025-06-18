# 🚀 Trajetória de Estudos: C++ para WebAssembly e Node.js

## 📚 Sobre Esta Jornada

Este repositório documenta minha trajetória de estudos autodidatas em **C++**, com foco no desenvolvimento de uma biblioteca JavaScript que utiliza **WebAssembly (WASM)** e **Node.js**. O objetivo final é criar uma biblioteca de alto desempenho que combine a velocidade do C++ com a flexibilidade do JavaScript.

## 🎯 Objetivo Final

**Criar uma biblioteca JavaScript que:**
- Utilize C++ compilado para WebAssembly para operações computacionalmente intensivas
- Seja integrada com Node.js para uso no backend
- Ofereça APIs JavaScript simples e intuitivas
- Mantenha a performance próxima ao código nativo

## 🛠️ Configuração do Ambiente de Desenvolvimento

### 1. Instalação do Visual Studio Code

1. Baixe e instale o [Visual Studio Code](https://code.visualstudio.com/)
2. Abra o VS Code e instale as seguintes extensões:
   - **C/C++** (Microsoft) - Suporte principal para C++
   - **C/C++ Extension Pack** - Pacote completo com debugging e IntelliSense
   - **Code Runner** - Para executar código rapidamente
   - **C++ Intellisense** - Autocompletar e navegação de código

### 2. Instalação do MinGW-w64 (Compilador C++)

#### Windows:
1. Baixe o **MinGW-w64** do site oficial ou use o [MSYS2](https://www.msys2.org/)
2. Durante a instalação, selecione:
   - **Architecture**: x86_64
   - **Threads**: posix
   - **Exception**: seh
   - **Build revision**: mais recente

#### Alternativa via Chocolatey:
```bash
choco install mingw
```

### 3. Configuração das Variáveis de Ambiente

1. Abra as **Variáveis de Ambiente do Sistema**
2. Em **Variáveis do Sistema**, encontre **Path**
3. Clique em **Editar** e adicione o caminho para o MinGW-w64:
   ```
   C:\mingw64\bin
   ```
   (Ajuste o caminho conforme sua instalação)

4. **Reinicie o terminal/VS Code** para aplicar as mudanças

### 4. Verificação da Instalação

Abra um terminal e execute:
```bash
g++ --version
```

Se tudo estiver configurado corretamente, você verá a versão do compilador.

## 🏃‍♂️ Como Compilar e Executar Códigos

### Comando Básico de Compilação:
```bash
g++ nome_do_arquivo.cpp -o nome_do_programa
```

### Exemplos Práticos:
```bash
# Compilar um arquivo simples
g++ hello.cpp -o hello

# Compilar múltiplos arquivos
g++ arquivo1.cpp arquivo2.cpp -o programa

# Compilar com otimizações
g++ -O2 programa.cpp -o programa_otimizado

# Compilar com warnings
g++ -Wall -Wextra programa.cpp -o programa

# Executar o programa
./programa
```

### Configuração do VS Code para C++

Crie um arquivo `.vscode/tasks.json`:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileBasenameNoExtension}.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

## 📈 Progresso e Nível de Aprendizado

### 🎓 Fases de Estudo:

#### **Fase 1: Fundamentos (Concluída)**
- ✅ Sintaxe básica do C++
- ✅ Estruturas de controle
- ✅ Funções e escopo
- ✅ Arrays e strings
- ✅ Ponteiros básicos

#### **Fase 2: Conceitos Intermediários (Em Andamento)**
- 🔄 Classes e objetos
- 🔄 Herança e polimorfismo
- 🔄 Templates
- 🔄 Gerenciamento de memória
- 🔄 STL (Standard Template Library)

#### **Fase 3: Avançado (Planejado)**
- ⏳ Otimizações de performance
- ⏳ Compilação para WebAssembly
- ⏳ Integração com Node.js
- ⏳ Desenvolvimento da biblioteca

### 📊 Métricas de Desempenho:

- **Tempo de Estudo**: ~X horas por semana
- **Projetos Concluídos**: X exercícios práticos
- **Conceitos Dominados**: X/20 tópicos principais
- **Próximo Milestone**: Implementar primeira função WASM

## 🎯 Próximos Passos

1. **Completar conceitos OOP** em C++
2. **Estudar Emscripten** para compilação WASM
3. **Aprender Node.js Addons** com N-API
4. **Desenvolver protótipos** da biblioteca
5. **Otimizar performance** e benchmarking

## 📁 Estrutura do Projeto

```
libs com C++ wasm e Node/
├── exercicio1/          # Primeiros exercícios básicos
├── exercicio2/          # Estruturas de dados
├── exercicio3/          # Funções e ponteiros
├── exercicio4/          # Classes e objetos
├── exercicio5/          # Herança e polimorfismo
├── exercicio6/          # Templates
├── exercicio7/          # STL
├── exercicio8/          # Gerenciamento de memória
├── exercicio9/          # Otimizações
├── exercicio10/         # Preparação para WASM
├── exercicio11/         # Primeiros testes WASM
├── treino1/             # Exercícios de reforço
├── treino2/             # Projetos práticos
├── treino3/             # Desafios avançados
├── treino4/             # Otimizações de código
├── treino5/             # Preparação para biblioteca
├── hello/               # Primeiro programa "Hello World"
├── .vscode/             # Configurações do VS Code
└── Anotacoes.docx       # Notas de estudo
```

## 🔧 Recursos Úteis

### Documentação:
- [C++ Reference](https://en.cppreference.com/)
- [Emscripten Documentation](https://emscripten.org/docs/)
- [Node.js Addons](https://nodejs.org/api/addons.html)

### Ferramentas:
- [Compiler Explorer](https://godbolt.org/) - Para testar código online
- [C++ Shell](http://cpp.sh/) - Compilador online
- [WASM Studio](https://webassembly.studio/) - IDE para WebAssembly

### Cursos e Tutoriais:
- C++ Primer (Livro)
- LearnCpp.com
- C++ Core Guidelines

## 💡 Dicas de Estudo

1. **Pratique diariamente** - Mesmo 30 minutos fazem diferença
2. **Implemente projetos pessoais** - Aplique o que aprendeu
3. **Leia código de outros** - GitHub é uma excelente fonte
4. **Participe de comunidades** - Stack Overflow, Reddit r/cpp
5. **Mantenha um log** - Documente seu progresso

## 🎉 Motivação

> *"A jornada de mil milhas começa com um único passo."* - Lao Tzu

Cada exercício, cada erro, cada linha de código é um passo em direção ao objetivo final: criar uma biblioteca que combine o melhor de dois mundos - a performance do C++ e a flexibilidade do JavaScript.

---

**Última atualização**: Dezembro 2024  
**Status**: Em desenvolvimento ativo  
**Próximo objetivo**: Implementar primeira função C++ → WASM 