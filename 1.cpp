#include <stdio.h>
#include <TXLib.h>
#include <math.h>
int main(void)
{
    float a;
    float b;
    float c;
    float ans1;
    float ans2;

    printf("��� ����������� ��������� ��� ������� ���������� ���������\n");

    printf("���������� ��������� ����� ���: \n");

    printf("ax^2 + bx + c = 0 \n");

    printf("�������� ���������� a \n");
    scanf("%f", &a);

    printf("�������� ���������� b \n");
    scanf("%f", &b);

    printf("�������� ���������� c \n");
    scanf("%f", &c);

    if (a >= 0.0 and a <= 0.0 and b >= 0.0 and b <= 0.0)
    {
        printf("��������� ������ �� ������");
    }


    else if(a >= 0.0 and a <= 0.0)
    {
        printf("��� ��������� �������� ��������, � �� ���������� \n");
        ans1 = - c / b;
        printf("������� ����� ���������: %f", ans1);
    }

    else
    {

        float D;
        D = (float) pow(b,2.0) - 4*a*c;

        if (D<0)
        {
         printf("������� ���!");

        }

        else if(D>=0 and D<=0)
        {
            ans1 = - b / (2 * a);
            printf("������� ����� ��������� ������ ����: %f", ans1);
        }

        else
        {
         ans1 = (float) (- b  + pow(D, 1 / 2.0)) / (2 * a);
         ans2 = (float) (- b  - pow(D, 1 / 2.0)) / (2 * a);

         printf("������� ����� ���������: %f ", ans1);
         printf(" � %f", ans2);

        }


    }



    return 0;
}
