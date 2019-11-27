![S.A.P.O.](/images/sapo_menor.png)
# robosapo
S.A.P.O. - Seguidor Autônomo de Percurso Orientado

S.A.P.O. é um robô criado como projeto interdisciplinar para a Universidade Tuiuti do Paraná.
Sua função é transportar uma carga por um percurso que simula uma linha de produção, respeitando curvas, subidas e descidas, bem como evitar colidir com obstáculos que possam interferir em seu caminho.

O cérebro do robô é um microcontrolador Arduino Mega que recebe dados de alguns sensores, e a partir desses dados controla os motores.

Os sensores são:
- Sensor de Ultrassom: verifica se há obstáculo à frente
- Sensores Infravermelhos: detectam a posição do robô em cima da linha
- Sensor Giroscópico: detecta subida e descida
- Sensor de Luminosidade: detecta a presença da carga

O controle do motor para fazer curvas se dá através de um algoritmo PID (Proporcional + Integral + Diferencial), o que garante ao robô um comportamento dinâmico em resposta às mudanças sobre a linha. Ele reage de três formas diferentes:
- Proporcional: ao detectar a necessidade de uma curva, o algoritmo altera a rotação dos motores.
- Integral: ao continuar detectando a necessida da curva, a intensidade da curva comandada aumenta (e continua aumentando com o tempo).
- Diferencial: caso seja detectada uma mudança brusca de direção, de um lado para o outro, o algoritmo responde com mais intensidade.

Além do robô seguidor de linha, nesse repositório também consta o código dos braços carregadores/descarregadores que ficam estáticos na linha de produção aguardando a chegada do robô.
