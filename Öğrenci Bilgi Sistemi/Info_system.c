#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

struct departmnents
{

    char name[15];

} dep[3] = {{"SENG"}, {"CENG"}, {"ME"}};

struct lessons
{

    char name[15];

} seng[4] = {{"YZM101"}, {"YZM102"}, {"YZM103"}, {"YZM104"}}, ceng[4] = {{"BGM101"}, {"BGM102"}, {"BGM103"}, {"BGM104"}}, me[4] = {{"MKM101"}, {"MKM102"}, {"MKM103"}, {"MKM104"}};

struct office
{
    char name[15];

    char surname[15];

    char password[10];
};

struct lecturers
{
    char name[15];

    char surname[15];

    char lesson[4][15];

    char id[15];

    char password[20];
};

struct students
{
    char name[15];

    char surname[15];

    int no;

    char department[30];

    struct lesson
    {

        char name[15];

        int semester;

        int AKTS;

        int midterm;

        int finalterm;

    } less1[4];

    char id[15];

    char password[10];
};

int administrator(char choice1[50], char choice2[50], char choice3[3], char words1[15], char words2[15], char words3[15], char words4[15][15], char words5[15][15], char words6[15][15], char words7[15][15], struct office off, struct lecturers lect1[4])
{
    char password[10] = {"kocaeli41"};

    int a = 0;

    while (a == 0)
    {
        printf("-Please enter your password : ");

        scanf("%s", choice1);

        if (strcmp(password, choice1) == 0)
        {
            printf("\nYou entered your password correctly and successfully logged in to the system.\n\n");

            int flag = 0;

            while (flag == 0)
            {
                printf("1-Appointment of an officer\n2-Appointment of a lecturer\n3-Return to main menu\n\n");
                scanf("%s", choice2);
                if (strcmp(choice2, "Officer") == 0)
                {
                    FILE *officerrr;
                    int index = 0;
                    if ((officerrr = fopen("officer.txt", "r")) != NULL)
                    {
                        while (!feof(officerrr))
                        {
                            fscanf(officerrr, "%s %s %s", &off.name[index], &off.surname[index], &off.password[index]);
                            index++;
                        }
                    }
                    fclose(officerrr);
                    if (strlen(off.name) == 0)
                    {
                        int flag1 = 0;
                        while (flag1 == 0)
                        {
                            printf("\nDo you want to appoint an officer to create the student information system?(Yes or No)\n");
                            scanf("%s", choice3);

                            if (strcmp(choice3, "Yes") == 0)
                            {
                                printf("Enter the name,surname and password of the officer : ");
                                scanf("%s %s %s", off.name, off.surname, off.password);
                                printf("\nCongrats.You have successfully deployed an officer!\n\n");
                                FILE *officerr;
                                officerr = fopen("officer.txt", "w");
                                fprintf(officerr, "%s %s %s", off.name, off.surname, off.password);
                                fclose(officerr);
                                flag1 = 1;
                            }
                            else if (strcmp(choice3, "No") == 0)
                            {
                                flag1 = 1;
                            }
                            else
                            {
                                printf("\nYou entered the wrong command.Please enter again.(Yes or No)\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nThere is already a registered officer in the system!\n\n");
                    }
                }
                else if (strcmp(choice2, "Lecturer") == 0)
                {
                    FILE *lecturerr;
                    int index = 0;
                    if ((lecturerr = fopen("lecturer.txt", "r")) != NULL)
                    {
                        while (!feof(lecturerr))
                        {
                            fscanf(lecturerr, "%s %s %s %s", &words4[index], &words5[index], &words6[index], &words7[index]);
                            index++;
                        }
                    }
                    fclose(lecturerr);

                    for (int i = 0; i < index; i++)
                    {
                        for (int j = 0; j < 15; j++)
                        {
                            lect1[i].name[j] = words4[i][j];
                            lect1[i].surname[j] = words5[i][j];
                            lect1[i].id[j] = words6[i][j];
                            lect1[i].password[j] = words7[i][j];
                        }
                    }
                    if (strlen(lect1[1].name) == 0)
                    {
                        int flag2 = 0;
                        while (flag2 == 0)
                        {
                            printf("\nDo you want to appoint an lecturer to create the student information system?(Yes or No)\n");
                            scanf("%s", choice3);

                            if (strcmp(choice3, "Yes") == 0)
                            {
                                for (int i = 0; i < 4; i++)
                                {
                                    printf("Enter the name,surname, id and password of the %d. lecturer : ", i + 1);
                                    scanf("%s %s %s %s", lect1[i].name, lect1[i].surname, lect1[i].id, lect1[i].password);
                                }
                                printf("\nCongrats.You have successfully deployed lecturers!\n\n");
                                FILE *lecturerr;
                                lecturerr = fopen("lecturer.txt", "w");
                                for (int i = 0; i < 4; i++)
                                {
                                    fprintf(lecturerr, "%s %s %s %s\n", lect1[i].name, lect1[i].surname, lect1[i].id, lect1[i].password);
                                }
                                fclose(lecturerr);
                                flag2 = 1;
                            }
                            else if (strcmp(choice3, "No") == 0)
                            {
                                flag2 = 1;
                            }
                            else
                            {
                                printf("\nYou entered the wrong command.Please enter again.(Yes or No)\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nThere is already a registered lecturers in the system!\n\n");
                    }
                }

                else if (strcmp(choice2, "Return") == 0)
                {
                    return;
                }

                else
                {
                    printf("\nYou entered the wrong command. Please enter again.(Officer,Lecturer,Return)\n\n");
                }
            }
        }
        else
        {
            printf("\nYou entered your password incorrectly.Please enter again.\n\n");
        }
    }
}

int officer(int number1, char choice35[15], char choice36[15], char choice[15], char choice0[15], char choice1[15], char choice2[15], char choice3[15], char choice4[15], char choice5[15], char choice6[15], char choice7[15], char choice8[15], char choice9[15], char choice10[15], char choice11[15], char choice12[15], char choice13[15], char choice14[15], char choice15[15], char choice16[15], char choice17[15], char choice18[15], char choice19[15], char choice20[15], char choice21[15], char choice22[15], char words1[15], char words2[15], char words3[15], char words4[15][15], char words5[15][15], char words6[15][15], char words7[15][15], char words8[15][15], char words9[15][15], char words10[15][15], char words11[15][15], char words12[15][15], int number2[100], struct office off, struct students stud1[100], struct lecturers lect1[4])
{
    FILE *officerrr;
    int index = 0;
    if ((officerrr = fopen("officer.txt", "r")) != NULL)
    {
        while (!feof(officerrr))
        {
            fscanf(officerrr, "%s %s %s", &off.name[index], &off.surname[index], &off.password[index]);
            index++;
        }
    }
    fclose(officerrr);

    if (strlen(off.name) != 0)
    {
        printf("\nThe registered officer found.\n");

        int flag = 0;

        while (flag == 0)
        {
            printf("-Enter the password provided to you to log in : ");

            scanf("%s", choice4);

            if (strcmp(choice4, off.password) == 0)
            {
                printf("\nWelcome %s %s.Please select an operation that you want to do:\n", off.name, off.surname);

                int flag1 = 0;

                while (flag1 == 0)
                {
                    printf("1-Register students\n2-Assign lessons to a lecturer\n3-Return to main menu\n\n");
                    scanf("%s", choice7);

                    if (strcmp(choice7, "Register") == 0)
                    {
                        FILE *studentss;
                        int index = 0;
                        if ((studentss = fopen("student.txt", "r")) != NULL)
                        {
                            while (!feof(studentss))
                            {
                                fscanf(studentss, "%s %s %d %s %s %s", &words8[index], &words9[index], &number2[index], &words10[index], &words11[index], &words12[index]);
                                index++;
                            }
                        }
                        fclose(studentss);

                        int a;

                        for (int i = 0; i < index; i++)
                        {
                            for (int j = 0; j < 15; j++)
                            {
                                stud1[i].name[j] = words8[i][j];
                                stud1[i].surname[j] = words9[i][j];
                                stud1[i].no = number2[i];
                                stud1[i].department[j] = words10[i][j];
                                stud1[i].id[j] = words11[i][j];
                                stud1[i].password[j] = words12[i][j];
                                a = i;
                            }
                        }
                        printf("\nHow many students will you enroll?\n");

                        scanf("%d", &number1);

                        int b = 0;

                        for (int i = a; i < number1 + a; i++)
                        {
                            printf("Enter the name,surname,no,department,id and password of the %d. student : ", b + 1);
                            scanf("%s %s %d %s %s %s", &stud1[i].name, &stud1[i].surname, &stud1[i].no, &stud1[i].department, &stud1[i].id, &stud1[i].password);
                            b++;
                        }
                        for (int i = 0; i < number1; i++)
                        {
                            if ((strcmp(stud1[i].department, dep[0].name) != 0) && (strcmp(stud1[i].department, dep[1].name) != 0) && (strcmp(stud1[i].department, dep[2].name) != 0))
                            {
                                printf("\nAn error occurred so!You entered a department name that is not defined in the system so students could not be registered.Returning main menu..\n");
                                strcpy(stud1[1].password, "");
                                return;
                            }
                            if (stud1[i].no == stud1[i + 1].no)
                            {
                                printf("\nAn error occurred!Some students have the same no as each other so students could not be registered.Returning main menu..\n");
                                strcpy(stud1[1].password, "");
                                return;
                            }
                            if ((strcmp(stud1[i].id, stud1[i + 1].id) == 0) && (strcmp(stud1[i].password, stud1[i + 1].password) == 0))
                            {
                                printf("\nAn error occured!Some students have the same username and password as each other so students could not be registered.Returning main menu..\n");
                                strcpy(stud1[1].password, "");
                                return;
                            }
                        }
                        printf("\nCongrats.You have successfully registered students!\n\n");
                        FILE *studentsss;
                        studentsss = fopen("student.txt", "a");
                        for (int i = a; i < number1 + a; i++)
                        {
                            fprintf(studentsss, "%s %s %d %s %s %s\n", stud1[i].name, stud1[i].surname, stud1[i].no, stud1[i].department, stud1[i].id, stud1[i].password);
                        }
                        fclose(studentsss);

                        for (int i = a; i < number1 + a; i++)
                        {
                            if (strcmp(stud1[i].department, dep[0].name) == 0)
                            {
                                FILE *seng101;

                                seng101 = fopen("YZM101-students.txt", "a");

                                fprintf(seng101, "%d\n", stud1[i].no);

                                fclose(seng101);

                                FILE *seng102;

                                seng102 = fopen("YZM102-students.txt", "a");

                                fprintf(seng102, "%d\n", stud1[i].no);

                                fclose(seng102);

                                FILE *seng103;

                                seng103 = fopen("YZM103-students.txt", "a");

                                fprintf(seng103, "%d\n", stud1[i].no);

                                fclose(seng103);

                                FILE *seng104;

                                seng104 = fopen("YZM104-students.txt", "a");

                                fprintf(seng104, "%d\n", stud1[i].no);

                                fclose(seng104);
                            }

                            if (strcmp(stud1[i].department, dep[1].name) == 0)
                            {
                                FILE *ceng101;

                                ceng101 = fopen("BGM101-students.txt", "a");

                                fprintf(ceng101, "%d\n", stud1[i].no);

                                fclose(ceng101);

                                FILE *ceng102;

                                ceng102 = fopen("BGM102-students.txt", "a");

                                fprintf(ceng102, "%d\n", stud1[i].no);

                                fclose(ceng102);

                                FILE *ceng103;

                                ceng103 = fopen("BGM103-students.txt", "a");

                                fprintf(ceng103, "%d\n", stud1[i].no);

                                fclose(ceng103);

                                FILE *ceng104;

                                ceng104 = fopen("BGM104-students.txt", "a");

                                fprintf(ceng104, "%d\n", stud1[i].no);

                                fclose(ceng104);
                            }

                            if (strcmp(stud1[i].department, dep[2].name) == 0)
                            {
                                FILE *meng101;

                                meng101 = fopen("ME101-students.txt", "a");

                                fprintf(meng101, "%d\n", stud1[i].no);

                                fclose(meng101);

                                FILE *meng102;

                                meng102 = fopen("ME102-students.txt", "a");

                                fprintf(meng102, "%d\n", stud1[i].no);

                                fclose(meng102);

                                FILE *meng103;

                                meng103 = fopen("ME103-students.txt", "a");

                                fprintf(meng103, "%d\n", stud1[i].no);

                                fclose(meng103);

                                FILE *meng104;

                                meng104 = fopen("ME104-students.txt", "a");

                                fprintf(meng104, "%d\n", stud1[i].no);

                                fclose(meng104);
                            }
                        }
                    }
                    else if (strcmp(choice7, "Assign") == 0)
                    {
                        FILE *lecturerr;
                        int index = 0;
                        if ((lecturerr = fopen("lecturer.txt", "r")) != NULL)
                        {
                            while (!feof(lecturerr))
                            {
                                fscanf(lecturerr, "%s %s %s %s", &words4[index], &words5[index], &words6[index], &words7[index]);
                                index++;
                            }
                        }
                        fclose(lecturerr);

                        for (int i = 0; i < index; i++)
                        {
                            for (int j = 0; j < 15; j++)
                            {
                                lect1[i].name[j] = words4[i][j];
                                lect1[i].surname[j] = words5[i][j];
                                lect1[i].id[j] = words6[i][j];
                                lect1[i].password[j] = words7[i][j];
                            }
                        }

                        FILE *lect;
                        int index1 = 0;
                        if ((lect = fopen("YZM101-lecturer.txt", "r")) != NULL)
                        {
                            while (!feof(lect))
                            {
                                fscanf(lect, "%s %s", &words1[index1], &words2[index1]);
                                index1++;
                            }
                        }
                        fclose(lect);

                        if (strlen(lect1[0].name) != 0)
                        {
                            if (strlen(words1) == 0)
                            {
                                printf("\nAssign a lecturer to the lessons in order.\n");

                                printf("\nAssign for software engineering department enter a lecture name and surname:\n");

                                printf("-%s : ", seng[0].name);

                                scanf("%s %s", choice11, choice0);

                                if (((strcmp(choice11, lect1[0].name) != 0) || (strcmp(choice0, lect1[0].surname) != 0)) && ((strcmp(choice11, lect1[1].name) != 0) || (strcmp(choice0, lect1[1].surname) != 0)) && ((strcmp(choice11, lect1[2].name) != 0) || (strcmp(choice0, lect1[2].surname) != 0)) && ((strcmp(choice11, lect1[3].name) != 0) || (strcmp(choice0, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\n-%s : ", seng[1].name);

                                scanf("%s %s", choice12, choice);

                                if (((strcmp(choice12, lect1[0].name) != 0) || (strcmp(choice, lect1[0].surname) != 0)) && ((strcmp(choice12, lect1[1].name) != 0) || (strcmp(choice, lect1[1].surname) != 0)) && ((strcmp(choice12, lect1[2].name) != 0) || (strcmp(choice, lect1[2].surname) != 0)) && ((strcmp(choice12, lect1[3].name) != 0) || (strcmp(choice, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\n-%s : ", seng[2].name);

                                scanf("%s %s", choice13, choice1);

                                if (((strcmp(choice13, lect1[0].name) != 0) || (strcmp(choice1, lect1[0].surname) != 0)) && ((strcmp(choice13, lect1[1].name) != 0) || (strcmp(choice1, lect1[1].surname) != 0)) && ((strcmp(choice13, lect1[2].name) != 0) || (strcmp(choice1, lect1[2].surname) != 0)) && ((strcmp(choice13, lect1[3].name) != 0) || (strcmp(choice1, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\n-%s : ", seng[3].name);

                                scanf("%s %s", choice35, choice36);

                                if (((strcmp(choice35, lect1[0].name) != 0) || (strcmp(choice36, lect1[0].surname) != 0)) && ((strcmp(choice35, lect1[1].name) != 0) || (strcmp(choice36, lect1[1].surname) != 0)) && ((strcmp(choice35, lect1[2].name) != 0) || (strcmp(choice36, lect1[2].surname) != 0)) && ((strcmp(choice35, lect1[3].name) != 0) || (strcmp(choice36, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\nAssign for computer engineering department enter a lecture name and surname:\n");

                                printf("-%s : ", ceng[0].name);

                                scanf("%s %s", choice15, choice3);

                                if (((strcmp(choice15, lect1[0].name) != 0) || (strcmp(choice3, lect1[0].surname) != 0)) && ((strcmp(choice15, lect1[1].name) != 0) || (strcmp(choice3, lect1[1].surname) != 0)) && ((strcmp(choice15, lect1[2].name) != 0) || (strcmp(choice3, lect1[2].surname) != 0)) && ((strcmp(choice15, lect1[3].name) != 0) || (strcmp(choice3, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\n-%s : ", ceng[1].name);

                                scanf("%s %s", choice16, choice4);

                                if (((strcmp(choice16, lect1[0].name) != 0) || (strcmp(choice4, lect1[0].surname) != 0)) && ((strcmp(choice16, lect1[1].name) != 0) || (strcmp(choice4, lect1[1].surname) != 0)) && ((strcmp(choice16, lect1[2].name) != 0) || (strcmp(choice4, lect1[2].surname) != 0)) && ((strcmp(choice16, lect1[3].name) != 0) || (strcmp(choice4, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\n-%s : ", ceng[2].name);

                                scanf("%s %s", choice17, choice5);

                                if (((strcmp(choice17, lect1[0].name) != 0) || (strcmp(choice5, lect1[0].surname) != 0)) && ((strcmp(choice17, lect1[1].name) != 0) || (strcmp(choice5, lect1[1].surname) != 0)) && ((strcmp(choice17, lect1[2].name) != 0) || (strcmp(choice5, lect1[2].surname) != 0)) && ((strcmp(choice17, lect1[3].name) != 0) || (strcmp(choice5, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\n-%s : ", ceng[3].name);

                                scanf("%s %s", choice18, choice6);

                                if (((strcmp(choice18, lect1[0].name) != 0) || (strcmp(choice6, lect1[0].surname) != 0)) && ((strcmp(choice18, lect1[1].name) != 0) || (strcmp(choice6, lect1[1].surname) != 0)) && ((strcmp(choice18, lect1[2].name) != 0) || (strcmp(choice6, lect1[2].surname) != 0)) && ((strcmp(choice18, lect1[3].name) != 0) || (strcmp(choice6, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\nAssign for mechanical engineering department enter a lecture name and surname:\n");

                                printf("-%s : ", me[0].name);

                                scanf("%s %s", choice19, choice7);

                                if (((strcmp(choice19, lect1[0].name) != 0) || (strcmp(choice7, lect1[0].surname) != 0)) && ((strcmp(choice19, lect1[1].name) != 0) && (strcmp(choice7, lect1[1].surname) != 0)) && ((strcmp(choice19, lect1[2].name) != 0) && (strcmp(choice7, lect1[2].surname) != 0)) && ((strcmp(choice19, lect1[3].name) != 0) && (strcmp(choice7, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\n-%s : ", me[1].name);

                                scanf("%s %s", choice20, choice8);

                                if (((strcmp(choice20, lect1[0].name) != 0) || (strcmp(choice8, lect1[0].surname) != 0)) && ((strcmp(choice20, lect1[1].name) != 0) || (strcmp(choice8, lect1[1].surname) != 0)) && ((strcmp(choice20, lect1[2].name) != 0) || (strcmp(choice8, lect1[2].surname) != 0)) && ((strcmp(choice20, lect1[3].name) != 0) || (strcmp(choice8, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\n-%s : ", me[2].name);

                                scanf("%s %s", choice21, choice9);

                                if (((strcmp(choice21, lect1[0].name) != 0) || (strcmp(choice9, lect1[0].surname) != 0)) && ((strcmp(choice21, lect1[1].name) != 0) || (strcmp(choice9, lect1[1].surname) != 0)) && ((strcmp(choice21, lect1[2].name) != 0) || (strcmp(choice9, lect1[2].surname) != 0)) && ((strcmp(choice21, lect1[3].name) != 0) || (strcmp(choice9, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                printf("\n-%s : ", me[3].name);

                                scanf("%s %s", choice22, choice10);

                                if (((strcmp(choice22, lect1[0].name) != 0) || (strcmp(choice10, lect1[0].surname) != 0)) && ((strcmp(choice22, lect1[1].name) != 0) || (strcmp(choice10, lect1[1].surname) != 0)) && ((strcmp(choice22, lect1[2].name) != 0) || (strcmp(choice10, lect1[2].surname) != 0)) && ((strcmp(choice22, lect1[3].name) != 0) || (strcmp(choice10, lect1[3].surname) != 0)))
                                {
                                    printf("\nThe entered lecturer was not found in the system!The class could not be opened.Returning main menu.\n");
                                    return;
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice11, lect1[i].name) == 0) && (strcmp(choice0, lect1[i].surname) == 0))
                                    {
                                        FILE *yzm101a;

                                        yzm101a = fopen("YZM101-lecturer.txt", "w");

                                        fprintf(yzm101a, "%s %s", choice11, choice0);

                                        fclose(yzm101a);

                                        FILE *yzm101;

                                        yzm101 = fopen("YZM101-notes.txt", "w");

                                        fclose(yzm101);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice12, lect1[i].name) == 0) && (strcmp(choice, lect1[i].surname) == 0))
                                    {
                                        FILE *yzm102a;

                                        yzm102a = fopen("YZM102-lecturer.txt", "w");

                                        fprintf(yzm102a, "%s %s", choice12, choice);

                                        fclose(yzm102a);

                                        FILE *yzm102;

                                        yzm102 = fopen("YZM102-notes.txt", "w");

                                        fclose(yzm102);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice13, lect1[i].name) == 0) && (strcmp(choice1, lect1[i].surname) == 0))
                                    {
                                        FILE *yzm103a;

                                        yzm103a = fopen("YZM103-lecturer.txt", "w");

                                        fprintf(yzm103a, "%s %s", choice13, choice1);

                                        fclose(yzm103a);

                                        FILE *yzm103;

                                        yzm103 = fopen("YZM103-notes.txt", "w");

                                        fclose(yzm103);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice35, lect1[i].name) == 0) && (strcmp(choice36, lect1[i].surname) == 0))
                                    {
                                        FILE *yzm104a;

                                        yzm104a = fopen("YZM104-lecturer.txt", "w");

                                        fprintf(yzm104a, "%s %s", choice35, choice36);

                                        fclose(yzm104a);

                                        FILE *yzm104;

                                        yzm104 = fopen("YZM104-notes.txt", "w");

                                        fclose(yzm104);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice15, lect1[i].name) == 0) && (strcmp(choice3, lect1[i].surname) == 0))
                                    {
                                        FILE *bgm101a;

                                        bgm101a = fopen("BGM101-lecturer.txt", "w");

                                        fprintf(bgm101a, "%s %s", choice15, choice3);

                                        fclose(bgm101a);

                                        FILE *bgm101;

                                        bgm101 = fopen("BGM101-notes.txt", "w");

                                        fclose(bgm101);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice16, lect1[i].name) == 0) && (strcmp(choice4, lect1[i].surname) == 0))
                                    {
                                        FILE *bgm102a;

                                        bgm102a = fopen("BGM102-lecturer.txt", "w");

                                        fprintf(bgm102a, "%s %s", choice16, choice4);

                                        fclose(bgm102a);

                                        FILE *bgm102;

                                        bgm102 = fopen("BGM102-notes.txt", "w");

                                        fclose(bgm102);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice17, lect1[i].name) == 0) && (strcmp(choice5, lect1[i].surname) == 0))
                                    {
                                        FILE *bgm103a;

                                        bgm103a = fopen("BGM103-lecturer.txt", "w");

                                        fprintf(bgm103a, "%s %s", choice17, choice5);

                                        fclose(bgm103a);

                                        FILE *bgm103;

                                        bgm103 = fopen("BGM103-notes.txt", "w");

                                        fclose(bgm103);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice18, lect1[i].name) == 0) && (strcmp(choice6, lect1[i].surname) == 0))
                                    {
                                        FILE *bgm104a;

                                        bgm104a = fopen("BGM104-lecturer.txt", "w");

                                        fprintf(bgm104a, "%s %s", choice18, choice6);

                                        fclose(bgm104a);

                                        FILE *bgm104;

                                        bgm104 = fopen("BGM104-notes.txt", "w");

                                        fclose(bgm104);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice19, lect1[i].name) == 0) && (strcmp(choice7, lect1[i].surname) == 0))
                                    {
                                        FILE *me101a;

                                        me101a = fopen("ME101-lecturer.txt", "w");

                                        fprintf(me101a, "%s %s", choice19, choice7);

                                        fclose(me101a);

                                        FILE *me101;

                                        me101 = fopen("ME101-notes.txt", "w");

                                        fclose(me101);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice20, lect1[i].name) == 0) && (strcmp(choice8, lect1[i].surname) == 0))
                                    {
                                        FILE *me102a;

                                        me102a = fopen("ME102-lecturer.txt", "w");

                                        fprintf(me102a, "%s %s", choice20, choice8);

                                        fclose(me102a);

                                        FILE *me102;

                                        me102 = fopen("ME102-notes.txt", "w");

                                        fclose(me102);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice21, lect1[i].name) == 0) && (strcmp(choice9, lect1[i].surname) == 0))
                                    {
                                        FILE *me103a;

                                        me103a = fopen("ME103-lecturer.txt", "w");

                                        fprintf(me103a, "%s %s", choice21, choice9);

                                        fclose(me103a);

                                        FILE *me103;

                                        me103 = fopen("ME103-notes.txt", "w");

                                        fclose(me103);
                                    }
                                }

                                for (int i = 0; i < 4; i++)
                                {
                                    if ((strcmp(choice22, lect1[i].name) == 0) && (strcmp(choice10, lect1[i].surname) == 0))
                                    {
                                        FILE *me104a;

                                        me104a = fopen("ME104-lecturer.txt", "w");

                                        fprintf(me104a, "%s %s", choice22, choice10);

                                        fclose(me104a);

                                        FILE *me104;

                                        me104 = fopen("ME104-notes.txt", "w");

                                        fclose(me104);
                                    }
                                }
                                printf("\nThe lessons was opened with success.Returning main menu..\n");
                                return;
                            }
                            else
                            {
                                printf("\nAn error occured!The lecturers has already been assigned to the lessons.\n");
                            }
                        }
                        else
                        {
                            printf("\nThere are no registered lecturer in the system, so course assignments cannot be made!\n");
                        }
                    }
                    else if (strcmp(choice7, "Return") == 0)
                    {
                        return;
                    }
                    else
                    {
                        printf("\nYou entered the wrong command. Please enter again.(Register,Assign,Return)\n\n");
                    }
                }
            }
            else
            {
                printf("\nYou entered your password incorrectly.Please enter again.\n\n");
            }
        }
    }
    else
    {
        printf("\nThe registered officer was not found. First, appoint an officer!\n\n");
        return;
    }
}

int lecturer(char vocable1[15], char vocable2[15], char vocable3[15], char vocable4[15], char vocable5[15], char vocable6[15], char vocable7[15], char vocable8[15], char vocable9[15], char vocable10[15], char vocable11[15], char vocable12[15], char vocable13[15], char vocable14[15], char vocable15[15], char vocable16[15], char vocable17[15], char vocable18[15], char vocable19[15], char vocable20[15], char vocable21[15], char vocable22[15], char vocable23[15], char vocable24[15], char choice5[15], char choice6[15], char choice8[15], char words4[15][15], char words5[15][15], char words6[15][15], char words7[15][15], char words8[15][15], char words9[15][15], char words10[15][15], char words11[15][15], char words12[15][15], int number2[100], struct lecturers lect1[4], struct students stud1[100])
{
    int counting[100];
    int counter, counter1;
    FILE *lecturerr;
    int index = 0;
    if ((lecturerr = fopen("lecturer.txt", "r")) != NULL)
    {
        while (!feof(lecturerr))
        {
            fscanf(lecturerr, "%s %s %s %s", &words4[index], &words5[index], &words6[index], &words7[index]);
            index++;
        }
    }
    fclose(lecturerr);

    for (int i = 0; i < index; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            lect1[i].name[j] = words4[i][j];
            lect1[i].surname[j] = words5[i][j];
            lect1[i].id[j] = words6[i][j];
            lect1[i].password[j] = words7[i][j];
        }
    }
    if (strlen(lect1[1].name) != 0)
    {
        int flag = 0;

        printf("\nThe registered lecturers found.\n");

        while (flag == 0)
        {
            printf("-Enter the id       :");

            scanf("%s", choice5);

            printf("-Enter the password :");

            scanf("%s", choice6);

            for (int i = 0; i < 4; i++)
            {
                if ((strcmp(choice5, lect1[i].id) == 0) && (strcmp(choice6, lect1[i].password) == 0))
                {
                    printf("\nWelcome %s %s.Please select an operation that you want to do:\n", lect1[i].name, lect1[i].surname);

                    int flag1 = 0;

                    while (flag1 == 0)
                    {
                        printf("1-Enter the notes\n2-Return to main menu\n\n");
                        scanf("%s", choice8);

                        if (strcmp(choice8, "Notes") == 0)
                        {
                            FILE *studentss;
                            int index = 0;
                            if ((studentss = fopen("student.txt", "r")) != NULL)
                            {
                                while (!feof(studentss))
                                {
                                    fscanf(studentss, "%s %s %d %s %s %s", &words8[index], &words9[index], &number2[index], &words10[index], &words11[index], &words12[index]);
                                    index++;
                                }
                            }

                            fclose(studentss);

                            for (int i = 0; i < index; i++)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    stud1[i].name[j] = words8[i][j];
                                    stud1[i].surname[j] = words9[i][j];
                                    stud1[i].no = number2[i];
                                    stud1[i].department[j] = words10[i][j];
                                    stud1[i].id[j] = words11[i][j];
                                    stud1[i].password[j] = words12[i][j];
                                }
                            }
                            int x = 0, y = 0, z = 0;

                            for (int i = 0; i < 100; i++)
                            {
                                if (strcmp(stud1[i].department, dep[0].name) == 0)
                                {
                                    x++;
                                }

                                if (strcmp(stud1[i].department, dep[1].name) == 0)
                                {
                                    y++;
                                }

                                if (strcmp(stud1[i].department, dep[2].name) == 0)
                                {
                                    z++;
                                }
                            }

                            FILE *lect;
                            int index1 = 0;
                            if ((lect = fopen("YZM101-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect))
                                {
                                    fscanf(lect, "%s %s", &vocable1[index1], &vocable2[index1]);
                                    index1++;
                                }
                            }
                            fclose(lect);

                            FILE *lectt1;
                            int index2 = 0;
                            if ((lectt1 = fopen("YZM102-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lectt1))
                                {
                                    fscanf(lectt1, "%s %s", &vocable3[index2], &vocable4[index2]);
                                    index2++;
                                }
                            }
                            fclose(lectt1);

                            FILE *lect2;
                            int index3 = 0;
                            if ((lect2 = fopen("YZM103-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect2))
                                {
                                    fscanf(lect2, "%s %s", &vocable5[index3], &vocable6[index3]);
                                    index3++;
                                }
                            }
                            fclose(lect2);

                            FILE *lect3;
                            int index4 = 0;
                            if ((lect3 = fopen("YZM104-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect3))
                                {
                                    fscanf(lect3, "%s %s", &vocable7[index4], &vocable8[index4]);
                                    index4++;
                                }
                            }
                            fclose(lect3);

                            FILE *lect4;
                            int index5 = 0;
                            if ((lect4 = fopen("BGM101-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect4))
                                {
                                    fscanf(lect4, "%s %s", &vocable9[index5], &vocable10[index5]);
                                    index5++;
                                }
                            }
                            fclose(lect4);

                            FILE *lect5;
                            int index6 = 0;
                            if ((lect5 = fopen("BGM102-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect5))
                                {
                                    fscanf(lect5, "%s %s", &vocable11[index6], &vocable12[index6]);
                                    index6++;
                                }
                            }
                            fclose(lect5);

                            FILE *lect6;
                            int index7 = 0;
                            if ((lect6 = fopen("BGM103-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect6))
                                {
                                    fscanf(lect6, "%s %s", &vocable13[index7], &vocable14[index7]);
                                    index7++;
                                }
                            }
                            fclose(lect6);

                            FILE *lect7;
                            int index8 = 0;
                            if ((lect7 = fopen("BGM104-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect7))
                                {
                                    fscanf(lect7, "%s %s", &vocable15[index8], &vocable16[index8]);
                                    index8++;
                                }
                            }
                            fclose(lect7);

                            FILE *lect8;
                            int index9 = 0;
                            if ((lect8 = fopen("ME101-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect8))
                                {
                                    fscanf(lect8, "%s %s", &vocable17[index9], &vocable18[index9]);
                                    index9++;
                                }
                            }
                            fclose(lect8);

                            FILE *lect9;
                            int index10 = 0;
                            if ((lect9 = fopen("ME102-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect9))
                                {
                                    fscanf(lect9, "%s %s", &vocable19[index10], &vocable20[index10]);
                                    index10++;
                                }
                            }
                            fclose(lect9);

                            FILE *lect10;
                            int index11 = 0;
                            if ((lect10 = fopen("ME103-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect10))
                                {
                                    fscanf(lect10, "%s %s", &vocable21[index11], &vocable22[index11]);
                                    index11++;
                                }
                            }
                            fclose(lect10);

                            FILE *lect11;
                            int index12 = 0;
                            if ((lect11 = fopen("ME104-lecturer.txt", "r")) != NULL)
                            {
                                while (!feof(lect11))
                                {
                                    fscanf(lect11, "%s %s", &vocable23[index12], &vocable24[index12]);
                                    index12++;
                                }
                            }
                            fclose(lect11);

                            if (strlen(vocable1) != 0)
                            {
                                if (strcmp(lect1[i].name, vocable1) == 0)
                                {
                                    FILE *stude;
                                    int index13 = 0;
                                    if ((stude = fopen("YZM101-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index13]);
                                            index13++;
                                        }
                                    }
                                    for (int i = 0; i < x; i++)
                                    {

                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], seng[0].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], seng[0].name);

                                        scanf("%d", &counter1);

                                        FILE *yzm101;

                                        yzm101 = fopen("YZM101-notes.txt", "a");

                                        fprintf(yzm101, "%d %d\n", counter, counter1);

                                        fclose(yzm101);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable3) == 0)
                                {
                                    FILE *stude;
                                    int index14 = 0;
                                    if ((stude = fopen("YZM102-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index14]);
                                            index14++;
                                        }
                                    }
                                    for (int i = 0; i < x; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], seng[1].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], seng[1].name);

                                        scanf("%d", &counter1);

                                        FILE *yzm102;

                                        yzm102 = fopen("YZM102-notes.txt", "a");

                                        fprintf(yzm102, "%d %d\n", counter, counter1);

                                        fclose(yzm102);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable5) == 0)
                                {
                                    FILE *stude;
                                    int index15 = 0;
                                    if ((stude = fopen("YZM103-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index15]);
                                            index15++;
                                        }
                                    }
                                    for (int i = 0; i < x; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], seng[2].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], seng[2].name);

                                        scanf("%d", &counter1);

                                        FILE *yzm103;

                                        yzm103 = fopen("YZM103-notes.txt", "a");

                                        fprintf(yzm103, "%d %d\n", counter, counter1);

                                        fclose(yzm103);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable7) == 0)
                                {
                                    FILE *stude;
                                    int index16 = 0;
                                    if ((stude = fopen("YZM104-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index16]);
                                            index16++;
                                        }
                                    }
                                    for (int i = 0; i < x; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], seng[3].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], seng[3].name);

                                        scanf("%d", &counter1);

                                        FILE *yzm104;

                                        yzm104 = fopen("YZM104-notes.txt", "a");

                                        fprintf(yzm104, "%d %d\n", counter, counter1);

                                        fclose(yzm104);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable9) == 0)
                                {
                                    FILE *stude;
                                    int index17 = 0;
                                    if ((stude = fopen("BGM101-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index17]);
                                            index17++;
                                        }
                                    }
                                    for (int i = 0; i < y; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], ceng[0].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], ceng[0].name);

                                        scanf("%d", &counter1);

                                        FILE *bgm101;

                                        bgm101 = fopen("BGM101-notes.txt", "a");

                                        fprintf(bgm101, "%d %d\n", counter, counter1);

                                        fclose(bgm101);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable11) == 0)
                                {
                                    FILE *stude;
                                    int index18 = 0;
                                    if ((stude = fopen("BGM102-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index18]);
                                            index18++;
                                        }
                                    }
                                    for (int i = 0; i < y; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], ceng[1].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], ceng[1].name);

                                        scanf("%d", &counter1);

                                        FILE *bgm102;

                                        bgm102 = fopen("BGM102-notes.txt", "a");

                                        fprintf(bgm102, "%d %d\n", counter, counter1);

                                        fclose(bgm102);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable13) == 0)
                                {
                                    FILE *stude;
                                    int index19 = 0;
                                    if ((stude = fopen("BGM103-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index19]);
                                            index19++;
                                        }
                                    }
                                    for (int i = 0; i < y; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], ceng[2].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], ceng[2].name);

                                        scanf("%d", &counter1);

                                        FILE *bgm103;

                                        bgm103 = fopen("BGM103-notes.txt", "a");

                                        fprintf(bgm103, "%d %d\n", counter, counter1);

                                        fclose(bgm103);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable15) == 0)
                                {
                                    FILE *stude;
                                    int index20 = 0;
                                    if ((stude = fopen("BGM104-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index20]);
                                            index20++;
                                        }
                                    }
                                    for (int i = 0; i < y; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], ceng[3].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], ceng[3].name);

                                        scanf("%d", &counter1);

                                        FILE *bgm104;

                                        bgm104 = fopen("BGM104-notes.txt", "a");

                                        fprintf(bgm104, "%d %d\n", counter, counter1);

                                        fclose(bgm104);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable17) == 0)
                                {
                                    FILE *stude;
                                    int index21 = 0;
                                    if ((stude = fopen("ME101-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index21]);
                                            index21++;
                                        }
                                    }
                                    for (int i = 0; i < z; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], me[0].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], me[0].name);

                                        scanf("%d", &counter1);

                                        FILE *me101;

                                        me101 = fopen("ME101-notes.txt", "a");

                                        fprintf(me101, "%d %d\n", counter, counter1);

                                        fclose(me101);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable19) == 0)
                                {
                                    FILE *stude;
                                    int index22 = 0;
                                    if ((stude = fopen("ME102-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index22]);
                                            index22++;
                                        }
                                    }
                                    for (int i = 0; i < z; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], me[1].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], me[1].name);

                                        scanf("%d", &counter1);

                                        FILE *me102;

                                        me102 = fopen("ME102-notes.txt", "a");

                                        fprintf(me102, "%d %d\n", counter, counter1);

                                        fclose(me102);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable21) == 0)
                                {
                                    FILE *stude;
                                    int index23 = 0;
                                    if ((stude = fopen("ME103-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index23]);
                                            index23++;
                                        }
                                    }
                                    for (int i = 0; i < z; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], me[2].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], me[2].name);

                                        scanf("%d", &counter1);

                                        FILE *me103;

                                        me103 = fopen("ME103-notes.txt", "a");

                                        fprintf(me103, "%d %d\n", counter, counter1);

                                        fclose(me103);
                                    }
                                }

                                if (strcmp(lect1[i].name, vocable23) == 0)
                                {
                                    FILE *stude;
                                    int index24 = 0;
                                    if ((stude = fopen("ME101-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stude))
                                        {
                                            fscanf(stude, "%d", &counting[index24]);
                                            index24++;
                                        }
                                    }
                                    for (int i = 0; i < z; i++)
                                    {
                                        printf("\nEnter the vize grades of the student whose number is %d for the %s lesson :  ", counting[i], me[3].name);

                                        scanf("%d", &counter);

                                        printf("\nEnter the final grades of the student whose number is %d for the %s lesson :  ", counting[i], me[3].name);

                                        scanf("%d", &counter1);

                                        FILE *me104;

                                        me104 = fopen("ME104-notes.txt", "a");

                                        fprintf(me104, "%d %d\n", counter, counter1);

                                        fclose(me104);
                                    }
                                }
                                printf("\nYou have successfully entered the notes.\n");
                            }
                            else
                            {
                                printf("\nAn error occured!Lecturers were not assigned to the classes.First, appoint lecturers to lessons.\n");
                            }
                        }
                        else if (strcmp(choice8, "Return") == 0)
                        {
                            return;
                        }
                        else
                        {
                            printf("\nYou entered the wrong command. Please enter again.(Notes,Return)\n\n");
                        }
                    }
                }
            }

            for (int i = 0; i < 4; i++)
            {
                if ((strcmp(choice5, lect1[i].id) != 0) && (strcmp(choice6, lect1[i].password) != 0))
                {
                    printf("\nYou have entered your id or your password incorrectly.Please enter again.\n\n");
                    break;
                }
            }
        }
    }
    else
    {
        printf("\nThe registered lecturers was not found. First, appoint lecturers!\n\n");
        return;
    }
}

int student(int number2[100], struct students stud1[100], char choice9[15], char choice10[15], char choice[15], char words8[15][15], char words9[15][15], char words10[15][15], char words11[15][15], char words12[15][15])
{
    FILE *studentss;
    int index = 0;
    if ((studentss = fopen("student.txt", "r")) != NULL)
    {
        while (!feof(studentss))
        {
            fscanf(studentss, "%s %s %d %s %s %s", &words8[index], &words9[index], &number2[index], &words10[index], &words11[index], &words12[index]);
            index++;
        }
    }

    fclose(studentss);

    for (int i = 0; i < index; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            stud1[i].name[j] = words8[i][j];
            stud1[i].surname[j] = words9[i][j];
            stud1[i].no = number2[i];
            stud1[i].department[j] = words10[i][j];
            stud1[i].id[j] = words11[i][j];
            stud1[i].password[j] = words12[i][j];
        }
    }

    float a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], x[100], j[100], k[100], l[100], m[100], n[100], o[100], p[100], r[100], s[100], t[100], u[100], v[100], y[100], z[100], w[100];
    float overall, overall1, overall2, overall3, overall4;
    FILE *studentss1;
    int index1 = 0;
    if ((studentss1 = fopen("YZM101-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss1))
        {
            fscanf(studentss1, "%f %f", &a[index1], &b[index1]);
            index1++;
        }
    }

    fclose(studentss1);

    FILE *studentss2;
    int index2 = 0;
    if ((studentss2 = fopen("YZM102-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss2))
        {
            fscanf(studentss2, "%f %f", &c[index2], &d[index2]);
            index2++;
        }
    }

    fclose(studentss2);

    FILE *studentss3;
    int index3 = 0;
    if ((studentss3 = fopen("YZM103-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss3))
        {
            fscanf(studentss3, "%f %f", &e[index3], &f[index3]);
            index3++;
        }
    }

    fclose(studentss3);

    FILE *studentss4;
    int index4 = 0;
    if ((studentss4 = fopen("YZM104-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss4))
        {
            fscanf(studentss4, "%f %f", &g[index4], &h[index4]);
            index4++;
        }
    }

    fclose(studentss4);

    FILE *studentss5;
    int index5 = 0;
    if ((studentss5 = fopen("BGM101-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss5))
        {
            fscanf(studentss5, "%f %f", &x[index5], &j[index5]);
            index5++;
        }
    }

    fclose(studentss5);

    FILE *studentss6;
    int index6 = 0;
    if ((studentss6 = fopen("BGM102-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss6))
        {
            fscanf(studentss6, "%f %f", &k[index6], &l[index6]);
            index6++;
        }
    }

    fclose(studentss6);

    FILE *studentss7;
    int index7 = 0;
    if ((studentss7 = fopen("BGM103-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss7))
        {
            fscanf(studentss7, "%f %f", &m[index7], &n[index7]);
            index7++;
        }
    }

    fclose(studentss7);

    FILE *studentss8;
    int index8 = 0;
    if ((studentss8 = fopen("BGM104-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss8))
        {
            fscanf(studentss8, "%f %f", &o[index8], &p[index8]);
            index8++;
        }
    }

    fclose(studentss8);

    FILE *studentss9;
    int index9 = 0;
    if ((studentss9 = fopen("ME101-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss9))
        {
            fscanf(studentss9, "%f %f", &r[index9], &s[index9]);
            index9++;
        }
    }

    fclose(studentss9);

    FILE *studentss10;
    int index10 = 0;
    if ((studentss10 = fopen("ME102-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss10))
        {
            fscanf(studentss10, "%f %f", &t[index10], &u[index10]);
            index10++;
        }
    }

    fclose(studentss10);

    FILE *studentss11;
    int index11 = 0;
    if ((studentss11 = fopen("ME103-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss11))
        {
            fscanf(studentss11, "%f %f", &v[index11], &y[index11]);
            index11++;
        }
    }

    fclose(studentss11);

    FILE *studentss12;
    int index12 = 0;
    if ((studentss12 = fopen("ME104-notes.txt", "r")) != NULL)
    {
        while (!feof(studentss12))
        {
            fscanf(studentss12, "%f %f", &z[index12], &w[index12]);
            index12++;
        }
    }

    fclose(studentss12);

    if (strlen(stud1[1].password) != 0)
    {

        int flag = 0, num = 0;

        printf("\nThe registered students found.\n");

        while (flag == 0)
        {
            printf("-Enter the id       :");

            scanf("%s", choice9);

            printf("-Enter the password :");

            scanf("%s", choice10);

            for (int i = 0; i < 100; i++)
            {
                if ((strcmp(choice9, stud1[i].id) == 0) && (strcmp(choice10, stud1[i].password) == 0))
                {
                    printf("\nWelcome %s %s.Please select an operation that you want to do:\n", stud1[i].name, stud1[i].surname);

                    int flag = 0;

                    while (flag == 0)
                    {
                        printf("\n1-My Grades\n2-Student Certificate\n3-Return to main menu\n");

                        scanf("%s", choice);

                        if (strcmp(choice, "Grades") == 0)
                        {
                            num = 1;

                            if ((a[0] != 0))
                            {
                                int ab[100], cd[100], ef[100], gh[100], xj[100], kl[100], mn[100], op[100], rs[100], tu[100], vy[100], zw[100];

                                if (strcmp(stud1[i].department, dep[0].name) == 0)
                                {
                                    FILE *stu1;
                                    int index13 = 0;
                                    if ((stu1 = fopen("YZM101-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu1))
                                        {
                                            fscanf(stu1, "%d", &ab[index13]);
                                            index13++;
                                        }
                                    }

                                    fclose(stu1);

                                    FILE *stu2;
                                    int index14 = 0;
                                    if ((stu2 = fopen("YZM102-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu2))
                                        {
                                            fscanf(stu2, "%d", &cd[index14]);
                                            index14++;
                                        }
                                    }

                                    fclose(stu2);

                                    FILE *stu3;
                                    int index15 = 0;
                                    if ((stu3 = fopen("YZM103-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu3))
                                        {
                                            fscanf(stu3, "%d", &ef[index15]);
                                            index15++;
                                        }
                                    }

                                    fclose(stu3);

                                    FILE *stu4;
                                    int index16 = 0;
                                    if ((stu4 = fopen("YZM104-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu4))
                                        {
                                            fscanf(stu4, "%d", &gh[index16]);
                                            index16++;
                                        }
                                    }

                                    fclose(stu4);

                                    for (int j = 0; j < 100; j++)
                                    {
                                        if (stud1[i].no == ab[j])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note : %.2f\nYour overall grade : %.2f", seng[0].name, a[j], seng[0].name, b[j], (a[j] + b[j]) / 2, ((a[j] + b[j]) / 2) / 25);

                                            overall1 = ((a[j] + b[j]) / 2) / 25;

                                            if ((a[j] + b[j]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", seng[0].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", seng[0].name);
                                            }
                                        }

                                        if (stud1[i].no == cd[j])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", seng[1].name, c[j], seng[1].name, d[j], (c[j] + d[j]) / 2, ((c[j] + d[j]) / 2) / 25);

                                            overall2 = ((c[j] + d[j]) / 2) / 25;

                                            if ((c[j] + d[j]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", seng[1].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", seng[1].name);
                                            }
                                        }

                                        if (stud1[i].no == ef[j])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", seng[2].name, e[j], seng[2].name, f[j], (e[j] + f[j]) / 2, ((e[j] + f[j]) / 2) / 25);

                                            overall3 = ((e[j] + f[j]) / 2) / 25;

                                            if ((e[j] + f[j]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", seng[2].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", seng[2].name);
                                            }
                                        }

                                        if (stud1[i].no == gh[j])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", seng[3].name, g[j], seng[3].name, h[j], (g[j] + h[j]) / 2, ((g[j] + h[j]) / 2) / 25);

                                            overall4 = ((g[j] + h[j]) / 2) / 25;

                                            if ((g[j] + h[j]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", seng[3].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", seng[3].name);
                                            }
                                        }
                                        overall = (overall1 + overall2 + overall3 + overall4) / 4;
                                    }
                                }

                                if (strcmp(stud1[i].department, dep[1].name) == 0)
                                {
                                    FILE *stu5;
                                    int index17 = 0;
                                    if ((stu5 = fopen("BGM101-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu5))
                                        {
                                            fscanf(stu5, "%d", &xj[index17]);
                                            index17++;
                                        }
                                    }

                                    fclose(stu5);

                                    FILE *stu6;
                                    int index18 = 0;
                                    if ((stu6 = fopen("BGM102-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu6))
                                        {
                                            fscanf(stu6, "%d", &kl[index18]);
                                            index18++;
                                        }
                                    }

                                    fclose(stu6);

                                    FILE *stu7;
                                    int index19 = 0;
                                    if ((stu7 = fopen("BGM103-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu7))
                                        {
                                            fscanf(stu7, "%d", &mn[index19]);
                                            index19++;
                                        }
                                    }

                                    fclose(stu7);

                                    FILE *stu8;
                                    int index20 = 0;
                                    if ((stu8 = fopen("BGM104-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu8))
                                        {
                                            fscanf(stu8, "%d", &op[index20]);
                                            index20++;
                                        }
                                    }

                                    fclose(stu8);

                                    for (int q = 0; q < 100; q++)
                                    {
                                        if (stud1[i].no == xj[q])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", ceng[0].name, x[q], ceng[0].name, j[q], (x[q] + j[q]) / 2, ((x[q] + j[q]) / 2) / 25);

                                            overall1 = ((x[q] + j[q]) / 2) / 25;

                                            if ((x[q] + j[q]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", ceng[0].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", ceng[0].name);
                                            }
                                        }

                                        if (stud1[i].no == kl[q])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", ceng[1].name, k[q], ceng[1].name, l[q], (k[q] + l[q]) / 2, ((k[q] + l[q]) / 2) / 25);

                                            overall2 = ((k[q] + l[q]) / 2) / 25;

                                            if ((k[q] + l[q]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", ceng[1].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", ceng[1].name);
                                            }
                                        }

                                        if (stud1[i].no == mn[q])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", ceng[2].name, m[q], ceng[2].name, n[q], (m[q] + n[q]) / 2, ((m[q] + n[q]) / 2) / 25);

                                            overall3 = ((m[q] + n[q]) / 2) / 25;

                                            if ((m[q] + n[q]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", ceng[2].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", ceng[2].name);
                                            }
                                        }

                                        if (stud1[i].no == op[q])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", ceng[3].name, o[q], ceng[3].name, p[q], (o[q] + p[q]) / 2, ((o[q] + p[q]) / 2) / 25);

                                            overall4 = ((o[q] + p[q]) / 2) / 25;

                                            if ((o[q] + p[q]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", ceng[3].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", ceng[3].name);
                                            }
                                        }

                                        overall = (overall1 + overall2 + overall3 + overall4) / 4;
                                    }
                                }

                                if (strcmp(stud1[i].department, dep[2].name) == 0)
                                {
                                    FILE *stu9;
                                    int index21 = 0;
                                    if ((stu9 = fopen("ME101-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu9))
                                        {
                                            fscanf(stu9, "%d", &rs[index21]);
                                            index21++;
                                        }
                                    }

                                    fclose(stu9);

                                    FILE *stu10;
                                    int index22 = 0;
                                    if ((stu10 = fopen("ME102-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu10))
                                        {
                                            fscanf(stu10, "%d", &tu[index22]);
                                            index22++;
                                        }
                                    }

                                    fclose(stu10);

                                    FILE *stu11;
                                    int index23 = 0;
                                    if ((stu11 = fopen("ME103-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu11))
                                        {
                                            fscanf(stu11, "%d", &vy[index23]);
                                            index23++;
                                        }
                                    }

                                    fclose(stu11);

                                    FILE *stu12;
                                    int index24 = 0;
                                    if ((stu12 = fopen("ME104-students.txt", "r")) != NULL)
                                    {
                                        while (!feof(stu12))
                                        {
                                            fscanf(stu12, "%d", &zw[index24]);
                                            index24++;
                                        }
                                    }

                                    fclose(stu12);

                                    for (int j = 0; j < 100; j++)
                                    {
                                        if (stud1[i].no == rs[j])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", me[0].name, r[j], me[0].name, s[j], (r[j] + s[j]) / 2, ((r[j] + s[j]) / 2) / 25);

                                            overall1 = ((r[j] + s[j]) / 2) / 25;

                                            if ((r[j] + s[j]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", me[0].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", me[0].name);
                                            }
                                        }

                                        if (stud1[i].no == tu[j])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", me[1].name, t[j], me[1].name, u[j], (t[j] + u[j]) / 2, ((t[j] + u[j]) / 2) / 25);

                                            overall2 = ((t[j] + u[j]) / 2) / 25;

                                            if ((t[j] + u[j]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", me[1].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", me[1].name);
                                            }
                                        }

                                        if (stud1[i].no == vy[j])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", me[2].name, v[j], me[2].name, y[j], (v[j] + y[j]) / 2, ((v[j] + y[j]) / 2) / 25);

                                            overall3 = ((v[j] + y[j]) / 2) / 25;

                                            if ((v[j] + y[j]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", me[2].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", me[2].name);
                                            }
                                        }

                                        if (stud1[i].no == zw[j])
                                        {
                                            printf("\nYour %s lesson vize note : %.2f\nYour %s lesson final note : %.2f\nYour average note %.2f\nYour overall grade : %.2f", me[3].name, z[j], me[3].name, w[j], (z[j] + w[j]) / 2, ((z[j] + w[j]) / 2) / 25);

                                            overall4 = ((z[j] + w[j]) / 2) / 25;

                                            if ((z[j] + w[j]) / 2 >= 50)
                                            {
                                                printf("\nYou have successfully passed the %s\n", me[3].name);
                                            }
                                            else
                                            {
                                                printf("\nYou failed the %s\n", me[3].name);
                                            }
                                        }

                                        overall = (overall1 + overall2 + overall3 + overall4) / 4;
                                    }
                                }
                            }
                            else
                            {
                                printf("\nNote information was not found.Notes must be entered first.\n");
                            }
                        }
                        else if (strcmp(choice, "Certificate") == 0)
                        {
                            if (num == 1)
                            {
                                printf("\n--------------Student certificate------------------\n\n");
                                printf("\nName          : %s", stud1[i].name);
                                printf("\nSurname       : %s", stud1[i].surname);
                                printf("\nNo            : %d", stud1[i].no);
                                printf("\nDepartment    : %s", stud1[i].name);
                                printf("\nOverall Grade : %.2f", overall);

                                if (overall < 2)
                                {
                                    printf("\nYou didn't graduate.\n");
                                }
                                else
                                {
                                    printf("\n\nYou have successfully passed the all lessons.You have graduated.\n");
                                }
                            }
                            else
                            {
                                printf("\nFirst you need to see his notes\n");
                            }
                        }
                        else if (strcmp(choice, "Return") == 0)
                        {
                            return;
                        }
                        else
                        {
                            printf("\nYou entered the wrong command. Please enter again.(Grades,Certificate,Return)\n");
                        }
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                if ((strcmp(choice9, stud1[i].id) != 0) && (strcmp(choice10, stud1[i].password) != 0))
                {
                    printf("\nYou have entered your id or your password incorrectly.Please enter again.\n\n");
                    break;
                }
            }
        }
    }
    else
    {
        printf("\nThe registered students was not found. First, register the students!\n\n");
        return;
    }
}

int main()
{
    setlocale(LC_ALL, "Turkish.turkish.1254");
    SetConsoleCP(1254);
    SetConsoleOutputCP(1254);

    FILE *file;

    int number, number2[100];

    char vocable1[15], vocable2[15], vocable3[15], vocable4[15], vocable5[15], vocable6[15], vocable7[15], vocable8[15], vocable9[15], vocable10[15], vocable11[15], vocable12[15], vocable13[15], vocable14[15], vocable15[15], vocable16[15], vocable17[15], vocable18[15], vocable19[15], vocable20[15], vocable21[15], vocable22[15], vocable23[15], vocable24[15];

    char choice35[15], choice36[15], choice0[50], choice[50], choice1[50], choice2[50], choice3[3], choice4[15], choice5[15], choice6[15], choice7[15], choice8[15], choice9[15], choice10[15], choice11[15], choice12[15], choice13[15], choice14[15], choice15[15], choice16[15], choice17[15], choice18[15], choice19[15], choice20[15], choice21[15], choice22[15], word[15], word1[15], word2[15], word3[15], word4[15][15], word5[15][15], word6[15][15], word7[15][15], word8[15][15], word9[15][15], word10[15][15], word11[15][15], word12[15][15];

    struct office off1;

    struct lecturers lect[4];

    struct students stud[100];

    printf("-----------------------------------------------STUDENT INFORMATION SYSTEM-----------------------------------------------\n");

    while (choice != "Exit")
    {
        printf("Welcome to the student information system(ÖBS).Who will you log in as?\n");

        printf("1-Administrator\n2-Officer\n3-Lecturer\n4-Student\n5-Exit\n\n");

        scanf("%s", choice);

        if (strcmp(choice, "Administrator") == 0)
        {
            administrator(choice1, choice2, choice3, word1, word2, word3, word4, word5, word6, word7, off1, lect);
        }

        else if (strcmp(choice, "Officer") == 0)
        {
            officer(number, choice35, choice36, choice0, choice, choice1, choice2, choice3, choice4, choice5, choice6, choice7, choice8, choice9, choice10, choice11, choice12, choice13, choice14, choice15, choice16, choice17, choice18, choice19, choice20, choice21, choice22, word1, word2, word3, word4, word5, word6, word7, word8, word9, word10, word11, word12, number2, off1, stud, lect);
        }

        else if (strcmp(choice, "Lecturer") == 0)
        {
            lecturer(vocable1, vocable2, vocable3, vocable4, vocable5, vocable6, vocable7, vocable8, vocable9, vocable10, vocable11, vocable12, vocable13, vocable14, vocable15, vocable16, vocable17, vocable18, vocable19, vocable20, vocable21, vocable22, vocable23, vocable24, choice5, choice6, choice8, word4, word5, word6, word7, word8, word9, word10, word11, word12, number2, lect, stud);
        }

        else if (strcmp(choice, "Student") == 0)
        {
            student(number2, stud, choice9, choice10, choice, word8, word9, word10, word11, word12);
        }

        else if (strcmp(choice, "Exit") == 0)
        {
            printf("You have succesfully exited the system. Have a good day.\n\n");
            return 0;
        }

        else
        {
            printf("\nYou entered the wrong command. Please enter again.(Administrator,Officer,Lecturer,Student,Exit)\n\n");
        }
    }
}
