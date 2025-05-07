#define FILE_ACC "NapKNB.ini"
#define USER_ID 0
#define KNB_NUMBER 1

void create()
{
    set_name("Kim Bảo Tổng Quản");
}

void NapKNB(int id)
{
}

int GetUserKNB(int userId)
{

    int knb = 0;
    string errstr, *line, *data;
    line = explode(read_file(FILE_ACC), "\n");

    for (i = 0, size = sizeof(line); i < size; i++)
    {
        data = explode(line[i], " ");
        if (userId == data[USER_ID])
        {
            knb = data[KNB_NUMBER];

            break;
        }
    }
}