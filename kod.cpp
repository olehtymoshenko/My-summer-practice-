/**
* @file   Summer practice.cpp
* @author ��������� �.�., ��. 515�
* @date   18 ���� 2018
* @brief  ������ ��������
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX_LEN 50 // ����. ����� �����

/**
* ������� ������ ������ ������� ��� �������� ����� � ������(����)
*
* @param hour - �-�� ����� � ������. �����. �������
* @return str_hour, ���� ������. �������, ��� NULL, ���� ���
*/
char * check_h(int hour); // �������� �-���� check_h

/**
* ������� ������ ������ ������� ��� �������� ����� � ������(������)
*
* @param min - �-�� ����� � ������. �����. �������
* @return str_min, ���� ������. �������, ��� NULL, ���� ���
*/
char * check_min(int min); // �������� �-���� check_min

/**
* ���������� ����� �� 2 �����
*
* @param *part-1 - ������ �����
* @param *part-2 - ������ �����
* @param num - �����
* @return ������ (��� ������ �-���� void)
*/
void dev_num(int * part_1, int * part_2, int num);

/**
* ������� �� ����� � ����� ��� ���� 0-9
*
* @param part_2 - ������ ����� �����
* @param *str_h - ������ ��� �������� ����� �������
* @return ������ (��� ������ �-���� void)
*/
void units_f(int part_2, char * str_h);

/**
* ������� �� ����� � ����� ��� ���� 11-19
*
* @param part_2 - ������ ����� �����
* @param *str_hour - ������ ��� �������� ����� �������
* @return ������ (��� ������ �-���� void)
*/
void teens(int num_2, char *  str_hour);

/**
* ������� �� ����� � ����� ��� ���� 10, 20, 30, 40, 50
*
* @param part_1 - ������ ����� �����
* @param *str_dec - ������ ��� �������� ����� �������
* @return ������ (��� ������ �-���� void)
*/
void decades(int part_1, char * str_dec);

/**
* ���������� ���������� ����� ����� "������"
*
* @param part_2 - ������ ����� �����
* @param *str_form - ������ ��� �������� ����� ������� � ����. ����� ����� ������
* @return ������ (��� ������ �-���� void)
*/
void form_hour(char * str_form, int part_2);

/**
* ���������� ���������� ����� ����� "�������"
*
* @param part_2 - ������ ����� �����
* @param *str_form - ������ ��� �������� ����� ������� � ����. ����� ����� �������
* @return ������ (��� ������ �-���� void)
*/
void form_min(char * str_form, int part_2);

const char * units[] = { "����", "����", "���", "���", "������", "�'���", "�i���", "�i�", "�i�i�", "���'���" }; // const ����. ��� ����
const char * dec[] = { "������", "��������", "��������", "�����", "�'�������" }; // const ����. ��� ��������
char * str_hour, *str_min; // ������ ��� �������� ����� ������� � ����. ����� ������� �����(������, �������)

int main()
{
	char * str_hour_m, *str_min_m; // ����. ��� ����. ����. ����. �-��� check_h, check_min
	setlocale(LC_ALL, "ukr"); // �����. ���. �����
	int part_hour, part_min, choice; // part_hour-������� ������. �������, part_min-�������� ����. �������, choice-�����. ��� ����. �����. �����.
	while (1) // ����. ����
	{
		printf("����i�� ��� �������(� ������i �� ��):");
		scanf_s("%d%d", &part_hour, &part_min); // ���� �������
		str_hour = (char*)calloc(MAX_LEN, sizeof(char)); // �����. ������ ��� str_hour
		str_min = (char*)calloc(MAX_LEN, sizeof(char)); // �����. ������ ��� str_min
		str_hour_m = check_h(part_hour); // �����. �-���� check_h, �����. str_hour_m ����. ����. ���� �-����
		str_min_m = check_min(part_min); // �����. �-���� check_min, �����. str_min_m ����. ����. ���� �-����
		if (str_hour_m == NULL || str_min_m == NULL) goto clear; // ���� �� �����. ������.
		strcat(str_hour, " "); // ���������� �������
		strcat(str_hour, str_min_m); // ���������� �������� ������. ������� � �������
		printf("�������� ��� �i������: %s\n", str_hour);  // �����. �����. �������
	clear: free(str_hour); // �����. ������
		free(str_min); // �����. ������
		printf("����i�� ����� 1, ���� ������ ����������, ��� 0, ���� ������ ����� � ���������:");
		scanf_s("%d", &choice); // ���� ������ �����.
		if (!choice) break; // ����� �� �����, ���� �����. ���� 0
	}
	return 0; // ������. ���������
}

char * check_h(int hour)  // �������� �-���� check_h
{
	int num_1, num_2; // ������ � ������ ����� �����
	if (hour < 0 || hour>23) { // ���� ���� ������ 0 ��� ������ 23, �� ������. �-����
		printf("�������� ��� ���i����\n");
		return NULL; // ����. NULL
	}
	dev_num(&num_1, &num_2, hour); // ����� �-���� ����. ����� �� 2 �����
	if (num_1 == 0) units_f(num_2, str_hour); // ���� ������ ����� = 0, �� ����� �-���� units_f
	if (num_1 == 1 && num_2 != 0) teens(num_2, str_hour); // ��� �����. ������� ����� �-���� teens
	if (num_1 != 0 && num_2 == 0) decades(num_1, str_hour); // ��� �����. ������� ����� �-���� decades
	if (num_1 > 1 && num_2 != 0) // ��� �����. ������� ����� �-���� decades � units_f
	{
		decades(num_1, str_hour);
		strcat(str_hour, " "); // �����. ������� � ������
		units_f(num_2, str_hour);
	}
	if (hour > 10 && hour < 20) { // ���� ��� ������ 10 � ������ 20, �� �����. � ������ "�����"
		strcat(str_hour, " �����"); // ���������� "�����"
	}
	else { // ���� hour �� ������ 10 ��� ������ 20, ��
		form_hour(str_hour, num_2); // ����� �-���� form_hour
	}
	return str_hour; // ����. ����. str_hour
}

char * check_min(int min) // �������� �-���� check_min
{
	int num_1, num_2; // ������ � ������ ����� �����
	if (min < 0 || min>59) { // ���� ������ ������ 0 ��� ������ 59, �� ������. �-����
		printf("�������� ��� ���i����\n");
		return NULL; // ����. NULL
	}
	dev_num(&num_1, &num_2, min); // ����� �-���� ����. ����� �� 2 �����
	if (num_1 == 0) units_f(num_2, str_min); // ���� ������ ����� = 0, �� ����� �-���� units_f
	if (num_1 == 1 && num_2 != 0) teens(num_2, str_min); // ��� �����. ������� ����� �-���� teens
	if (num_1 != 0 && num_2 == 0) decades(num_1, str_min); // ��� �����. ������� ����� �-���� decades
	if (num_1 > 1 && num_2 != 0) // ��� �����. ������� ����� �-���� decades � units_f
	{
		decades(num_1, str_min);
		strcat(str_min, " "); // �����. ������� � ������
		units_f(num_2, str_min);
	}
	if (min > 10 && min < 20) { // ���� ������ ������ 10 � ������ 20, �� �����. � ������ "������"
		strcat(str_min, " ������"); // ���������� "������"
	}
	else {  // ���� min �� ������ 10 ��� ������ 20, ��
		form_min(str_min, num_2); // ����� �-���� form_min
	}
	return str_min; // ����. ����. str_min
}