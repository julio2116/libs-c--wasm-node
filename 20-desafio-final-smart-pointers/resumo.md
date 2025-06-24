2. Resumo completo do Módulo: Smart Pointers e Gerenciamento de Memória em C++
Introdução
Neste módulo, você aprendeu os conceitos essenciais para a gestão segura e eficiente de memória em C++ moderno com foco no desenvolvimento de jogos na Unreal Engine.

Conteúdos abordados
2.1 Ponteiros, alocação e gerenciamento
Alocação dinâmica com new[] e delete[] (e seus problemas)

Uso do std::unique_ptr para propriedade exclusiva

Uso do std::shared_ptr para propriedade compartilhada (contagem de referência)

Uso do std::weak_ptr para observadores que não impedem a destruição

2.2 Comparação de performance
Comparação entre uso de vetor (std::vector) e arrays na heap

Medição de tempo usando std::chrono

Diferença entre alocação na stack e na heap

2.3 Aplicações práticas
Criação e destruição de objetos (exemplo da classe Jogador)

Sistemas que compartilham referências aos mesmos objetos (múltiplos sistemas compartilhando jogadores)

Controle de ciclo de vida e morte do objeto, com reflexo em sistemas observadores (HUD)

2.4 Conceitos importantes
Explicação detalhada do que é HUD (Heads-Up Display) — sistema gráfico que exibe informações do jogador sem controlar sua vida

RAII (Resource Acquisition Is Initialization) — conceito fundamental para evitar vazamentos usando objetos que gerenciam recursos automaticamente

Diferença entre ponteiros únicos, compartilhados e fracos e suas aplicações

2.5 Desafios práticos
Exercícios progressivos para fixação: criar jogadores, manipular smart pointers, implementar HUD com weak_ptr

Desafio final: sistema simplificado de combate multiplayer em console com jogadores vivos/mortos e gerenciamento automático de memória