#include <stdio.h>


void percentualMinMax(int area, float cr, float *min, float *max)
{
    if(cr < 7)
    {
        *max = 0.0;
        *min = 0.0;
    }
    else if (cr < 8)
    {
        *max = 0.05;
        *min = 0.05;
    }
    else if(cr < 9.0)
    {
        *min = 0.1;

        if(area == 1)
            *max = 0.15;
        else
            *max = 0.12;
    }
}

void quebraMatricula(int matricula, int *area, int *curso)
{
    *area = matricula / 10000;
    *curso = (matricula % 10000) / 1000;
}

void umAluno(int matricula, int numDisciplinas, float cr, float *min, float *max)
{
    int area, curso;
    double percentualBolsa=0;

    quebraMatricula(matricula, &area, &curso);
    percentualMinMax(area, cr, min, max);
    percentualBolsa = (*min + (0.05*numDisciplinas));

    printf("Percentual Minimo: %.2f",*min);
    printf("\nPercentual Maximo: %.2f",*max);

    if(percentualBolsa > *max)
    {
        printf("\nO percentual calculado ultrapassou o limite maximo: %.2f",percentualBolsa);
        percentualBolsa = *max;
    }

    printf("\nCurso: %d, Area do Curso: %d Percentual da Bolsa: %.2f\n", area,curso, percentualBolsa);
}

int recebeMatricula()
{
    int matricula;

    while ((matricula/10000 != 1 && matricula/10000 != 2) && matricula != 0)
    {
        printf("Digite a matricula do aluno (NDXXX): ");
        scanf("%d", &matricula);
        
        if ((matricula % 10000) / 1000 < 1 || (matricula % 10000) / 1000 > 9)
            matricula = 99999;
        else if(matricula % 1000 < 1 || matricula % 1000 > 999)
            matricula = 99999;
    }

    return matricula;
}

int main()
{
    int matricula, numDisciplinas=0;
    float cr=0.0, min, max;
    
    matricula = recebeMatricula();
    
    while (matricula != 0)
    {
        printf("Digite o numero de disciplinas cursadas: ");
        scanf("%d", &numDisciplinas);
        printf("Digite o CR do aluno: ");
        scanf("%f", &cr);
        UmAluno(matricula, numDisciplinas, cr, &min, &max);
        matricula = recebeMatricula();
    }
}
