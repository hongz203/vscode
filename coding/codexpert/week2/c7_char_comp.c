#include <stdio.h>

int M;      //���� �ݺ� �ּ� Ƚ��
char str[100+10];       //�Է� ���ڿ�

void solve()
{
    int count = 1;
    for(int i=1; str[i]; i++) {     //null ���ڸ� ���� �� ����
        if(str[i] != str[i-1]) {    //1��° ���ڿ� �� ���� (i-1)��° ���ڿ� ������ ��
            // count �� M���� ũ��
            if(count >= M) {
                printf("%c(%d)", str[i-1], count);
            }
            else {
                for(int j=0; j < count; j++) {
                    printf("%c", str[i-1]);
                }
            }
            //count�� �� ���������, �ٽ� 1�� �ʱ�ȭ
            count = 1;
        }
        else {  //���� ���ڿ� ���� ���
            count++;
        }
    }
    printf("\n");
}

void input()
{
    int i=0;
    scanf("%d", &M);
    scanf("%s", str);
    //null�����߰�ó��
    for(i=0; str[i]; i++);   //�� �ڷ� ����
    str[i] = ' '; str[i+1] = 0;
}

int main(void)
{
    input();    //�Է�

    //TODO:
    solve();

    return 0;
}