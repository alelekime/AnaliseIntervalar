# Analise Intervalar

A Análise Intervalar pode ser usada para computar operações básicas de forma rigorosa. A ideia é representar valores reais por intervalos de comprimento mínimo 
que contêm esses valores, ao invés de utilizar aproximações (para o número de máquina mais próximo, por exemplo). Deste modo, operações sobre esses números 
resultam em intervalos que carregam os erros numéricos de forma explícita, ao mesmo tempo que garantem a existência da solução real.

Seja x um valor real qualquer. A representação intervalar de x é dada por X = [m(x), M(x)], onde m(x) é o maior número de máquina menor ou igual a x e M(x) é o 
menor número de máquina maior ou igual a x.

Seja X = [a,b] e Y = [c,d]. As operações básicas intervalares são dadas por:

* *X + Y = [a+c, b+d]*

* *X - Y = [a-d, b-c]*

* *X * Y = [a,b] * [c,d]  =  [min{a*c,a*d,b*c,b*d}, max{a*c,a*d,b*c,b*d}]*

* *X / Y = [a,b] * [1/d,1/c], se 0 não pertence ao intervalo Y*

Para simplificar, considere que se 0 (zero)  pertence a Y, então **_X / Y =[-inf,+inf]_**, para qualquer intervalo X.

É importante notar que os limitantes dos intervalos resultantes devem ser representados na máquina de forma rigorosa. Assim, na prática:

* X + Y = [ m(a+c), M(b+d) ]

* X - Y = [ m(a-d), M(b-c) ]

E assim por diante...

                            
## Tarefa

Faça um programa que leia uma sequência de operações sobre valores reais e retorna os intervalos resultantes. Seu programa também deve informar se alguma operação resultou em um intervalo [a,b] não unitário (a < b). Para essa comparação (e outras que se façam necessárias), devem ser utilizadas estratégias de comparação de ponto flutuante adequadas, conforme visto em aula (epsilon absoluto, epsilon relativo e/ou ULP).

Os valores de entrada do programa devem ser lidos da entrada padrão (stdin) e devem ter o seguinte formato:

#### m  n
#### x1    3.1415
#### x2    0.1
#### x3    999.999
#### ...
#### xm   3.4567
#### x<m+1> = x<i> op x<j>       onde 1 <= i, j <= m    e  op  pode ser +, -, * ou /
#### ...
#### x<m+n> = x<i> op x<j>       onde 1 <= i, j <= m+n-1   e  op  pode ser +, -, * ou /

Onde m é o número de valores reais conhecidos, definidos nas m primeiras linhas do arquivo, e n é o número de operações que devem ser computadas. Cada operação resulta em um novo valor e os operandos são valores conhecidos ou que foram obtidos anteriormente.

O seu programa deve apresentar na saida padrão (stdout) os intervalos correspondentes de todas as variáveis x1, x2, ..., x<m+n> e uma lista dos intervalos não unitários das variáveis geradas pelas operações (x<m+1> , x<m+2> , ..., x<m+n>).

OBS.: Como uma operação pode resultar em [-inf, inf], casos particulares de operações aritméticas envolvendo estes operandos devem ser tratados com cuidado. Além disso, se em qualquer momento um intervalo inválido for gerado, o programa deve encerrar imediatamente, retornando -1. Exemplos de intervalos inválidos são: **_[2, 1], [-inf, -inf], [+inf, -inf], [+inf, +inf], [nan,nan]_**, etc. O mesmo vale para cálculo de intervalos em que ocorram overflow ou underflow.
