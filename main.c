//sleman hilal mohammed ghithan
//1202009
//sec 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Course{//Courses structure
    char CourseName [50] ;
    int CreditHours;
    char CourseCode [30];
    char Department [50];
    char Topics [150];
};
void linearPrint();//print the courses in the linear table
void doublePrint();//print the courses in the double table
void linearPrintSizeLoad();//print the size of linear table and its load factor
void doublePrintSizeLoad();//print the size of double table and its load factor
struct Course* linearMakeEmpty(struct Course  []);//clean all data from linear table
struct Course* doubleMakeEmpty(struct Course  []);//clean all data from double table
int linearHashing(struct Course [],char* );//to return the index of the node according to its hash value,for linear
int doubleHashing(struct Course [],char* );//to return the index of the node according to its hash value,for double
struct Course* linearInsert(struct Course [],char  [50], int ,char  [30],char  [50], char  [150]);//insert a node to linear table
struct Course* doubleInsert(struct Course [],char  [50], int ,char  [30],char  [50], char  [150]);//insert a node to double table
struct Course* linearInsertNew(struct Course [],char  [50], int ,char  [30],char  [50], char  [150]);//another insert without rehash,for linear
struct Course* doubleInsertNew(struct Course [],char  [50], int ,char  [30],char  [50], char  [150]);//another insert without rehash,for double
struct Course* fileReader(struct Course [],struct Course []);//read the data from the file
struct Course linearSearch(struct Course [],char CourseNameN [50]);//search for node in the linear table
void linearPrintCourse(struct Course  []);
void doublePrintCourse(struct Course  []);
struct Course doubleSearch(struct Course [],char  [50] );//search for node in the double table
struct Course* linearDelete(struct Course [],struct Course []);//delete a node from the linear table
struct Course* doubleDelete(struct Course [],char [50]);//delete a node from the double table
void printAll(struct Course []);//print all data in the table((not used in the project))
struct Course* insertCall(struct Course [],struct Course []);//calling the insert function
int findFirstPrimeAfter();//find the first prime number after the linear table current size
int doubleFindFirstPrimeAfter();//find the first prime number after the double table current size
int findFirstPrimeBefore(int );//find the first prime number before the number entered(used in double hashing)
void PrintOnFileCall();//calling the function of printing in the file
int isOdd(int );//check if the number entred is odd or not
int linearTableSize=2;//the linear table size (started with 2  )
int linearUsedCells=0;//the used cells in the linear table
int doubleTableSize=2;//the double table size (started with 2  )
int doubleUsedCells=0;//the used cells in the double table
int linearNumberOfCollision=0;//count the number of collisions in the linear table
int doubleNumberOfCollision=0;//count the number of collisions in the double table
struct Course* linearNewTable;//a global linear table to put the data on it after rehashing
struct Course* doubleNewTable;//a global double table to put the data on it after rehashing
int main() {
    struct Course linearMainTable [2];//a stating linear table (used to read file and transform data after rehashing)
    linearMakeEmpty(linearMainTable);//empty
    struct Course doubleMainTable [2];//a stating double table (used to read file and transform data after rehashing)
    doubleMakeEmpty(doubleMainTable);//empty
    fileReader(linearMainTable,doubleMainTable);//read the file data and insert it into both tables
    //int x=linearHashing(linearMainTable,"Arabic");
    //printf("%d\n\n\n",x);
    int choice=0;

    while (choice!=9) {//while the user don't enter 9 show the menu
        printf("1. Print hashed tables (including empty spots). \n"
               "2. Print out table size and the load factor. \n"
               "3. Print out the used hash functions. \n"
               "4. Insert a new record to hash table (insertion will be done on both hash tables). \n"
               "5. Search for a specific word (specify which table to search in). \n"
               "6. Delete a specific record (from both tables).\n"
               "7. Compare between the two methods in terms of number of collisions occurred.\n"
               "8. Save hash table back to a file named saved_courses.txt (of the double hashing)\n"
               "9 to exit\n");
        scanf("%d",&choice);
        if(choice==9){
            printf("thanks for using my app\n"
                   "made by sleman ghithan \n");
            return 0;
        }
        int printFlag=-1;//flag for printing data case check
        int printFlagSizeLoad=-1;//flag for printing size and load factor case check
        int printUsedFunction=-1;//flag for printing hashing functions case check
        int searchFlag=-1;//flag for search in the tables' case check
        switch (choice) {
            case 1:

                printf("witch table you want to print\n"
                       "enter 1 for linear hash table\n"
                       "enter 2 for double hash table\n"
                       "enter 3 for both tables\n");
                scanf("%d",&printFlag);
                if(printFlag==1){
                    linearPrint();
                }
                else if(printFlag==2){
                    doublePrint();
                }
                else if(printFlag==3){
                    printf("linear table:\n\n");
                    linearPrint();
                    printf("\ndouble table:\n\n");
                    doublePrint();

                }

                ;break;
            case 2:
                printf("witch table you want to print for\n"
                       "enter 1 for linear hash table\n"
                       "enter 2 for double hash table\n"
                       "enter 3 for both tables\n");
                scanf("%d",&printFlagSizeLoad);
                if(printFlagSizeLoad==1){
                    linearPrintSizeLoad();
                }
                else if(printFlagSizeLoad==2){
                    doublePrintSizeLoad();
                }
                else if(printFlagSizeLoad==3){
                    printf("linear table:\n\n");
                    linearPrintSizeLoad();
                    printf("\ndouble table:\n\n");
                    doublePrintSizeLoad();

                }

                ;break;
            case 3:

                printf("witch table you want to print for\n"
                       "enter 1 for linear hash table\n"
                       "enter 2 for double hash table\n"
                       "enter 3 for both tables\n");
                scanf("%d",&printUsedFunction);
                if(printUsedFunction==1){
                    printf("linear:\n"
                           " H(x)=((hash value for the name)+i)(reminder)linear table size\n"
                           "while i is number of collisions until find empty slot\n\n");
                    printf("------------------------------------------------------------------------------------------------------------------------");

                }
                else if(printUsedFunction==2){
                    printf("double\n"
                           "H(x)h1(x)+i*h2(x)\n"
                           "h1(x) is output of linear hashing\n"
                           "while i is number of collisions until find empty slot\n"
                           "h2(x)=R-(x(reminder)R)\n"
                           "R is the first prime number smaller then table size\n"
                           "x is hash value for the name\n\n");
                    printf("------------------------------------------------------------------------------------------------------------------------");

                }
                else if(printUsedFunction==3){
                    printf("linear:\n"
                           " H(x)=((hash value for the name)+i)%linear table size\n"
                           "while i is number of collisions until find empty slot\n");
                    printf("------------------------------------------------------------------------------------------------------------------------\n");
                    printf("double\n"
                           "H(x)h1(x)+i*h2(x)\n"
                           "h1(x) is output of linear hashing\n"
                           "while i is number of collisions until find empty slot\n"
                           "h2(x)=R-(x%R)\n"
                           "R is the first prime number smaller then table size\n"
                           "x is hash value for the name\n");
                    printf("------------------------------------------------------------------------------------------------------------------------\n");
                }

                ;break;
            case 4:
                insertCall( linearMainTable, doubleMainTable);
                break;

            case 5:
                printf("witch table you want to search\n"
                       "enter 1 for linear hash table\n"
                       "enter 2 for double hash table\n");
                scanf("%d",&searchFlag);
                if(searchFlag==1){
                    // void printCourse(struct Course linearMainTable [])
                    linearPrintCourse(linearNewTable);
                }
                else if(searchFlag==2){
                    doublePrintCourse(doubleNewTable);
                }
                ;break;
            case 6:
                linearDelete(linearNewTable,doubleNewTable);
                break;
            case 7:printf("linear got %d of collisions\n"
                          "while %d for double\n",linearNumberOfCollision,doubleNumberOfCollision);
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                break;
            case 8:
                PrintOnFileCall();break;

            case 9:printf("thanks for using my app\n");return 0;

        }
    }
    return 0;
}
void linearPrint(){
    int x=0;
    while(x<linearTableSize){//while the table has next
        if(strcmp(linearNewTable[x].CourseName,"\0")==0){//if null print null
            printf("index %d is Empty\n",x);
            printf("------------------------------------------------------------------------------------------------------------------------\n");
        }
        else{//if not null print data
            printf("the Course  in index %d\n",x);
            printf("name: %s\n",linearNewTable[x].CourseName);
            printf("hours: %d\n",linearNewTable[x].CreditHours);
            printf("code: %s\n",linearNewTable[x].CourseCode);
            printf("Department: %s\n",linearNewTable[x].Department);
            printf("topics: %s\n",linearNewTable[x].Topics);
            printf("------------------------------------------------------------------------------------------------------------------------\n");
        }
        x++;
    }
}
void doublePrint(){
    int x=0;
    while(x<doubleTableSize){//while the table has next
        if(strcmp(doubleNewTable[x].CourseName,"\0")==0){//if null print null
            printf("index %d is Empty\n",x);
            printf("------------------------------------------------------------------------------------------------------------------------\n");
        }
        else{//if not null print data
            printf("the Course  in index %d\n",x);
            printf("name: %s\n",doubleNewTable[x].CourseName);
            printf("hours: %d\n",doubleNewTable[x].CreditHours);
            printf("code: %s\n",doubleNewTable[x].CourseCode);
            printf("Department: %s\n",doubleNewTable[x].Department);
            printf("topics: %s\n",doubleNewTable[x].Topics);
            printf("------------------------------------------------------------------------------------------------------------------------\n");
        }
        x++;
    }
}
void linearPrintSizeLoad(){
    double load;
    load=(double)linearUsedCells/linearTableSize;//the load factor find

    printf("linear: size is %d and load factor is %f%\n",linearTableSize,load*100);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}
void doublePrintSizeLoad(){
    double load;
    load=(double)doubleUsedCells/doubleTableSize;//the load factor find
    printf("double: size is %d and load factor is %f%\n",doubleTableSize,load*100);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}
struct Course* linearRehash(struct Course linearMainTable[]){//rehashing used to change the table size and change data index according its hash value

    int temp=linearTableSize;//old size
    linearTableSize=findFirstPrimeAfter();//new size
    linearNewTable= malloc(linearTableSize*sizeof (struct Course));//change size
    linearMakeEmpty(linearNewTable);//clean
    int i=0;
    while (i<temp){//add data
        if(strcmp(linearMainTable[i].CourseName,"\0")!=0){
            linearNewTable= linearInsertNew(linearNewTable,linearMainTable[i].CourseName,linearMainTable[i].CreditHours,linearMainTable[i].CourseCode,linearMainTable[i].Department,linearMainTable[i].Topics);
        }
        i++;
    }
    return linearNewTable;
}
struct Course* doubleRehash(struct Course doubleMainTable[]){//rehashing used to change the table size and change data index according its hash value

    int temp=doubleTableSize;//old size
    doubleTableSize= doubleFindFirstPrimeAfter();//new size
    doubleNewTable= malloc(doubleTableSize*sizeof (struct Course));//change size
    doubleMakeEmpty(doubleNewTable);//clean
    int i=0;
    while (i<temp){//add data
        if(strcmp(doubleMainTable[i].CourseName,"\0")!=0){
            doubleNewTable= doubleInsertNew(doubleNewTable,doubleMainTable[i].CourseName,doubleMainTable[i].CreditHours,doubleMainTable[i].CourseCode,doubleMainTable[i].Department,doubleMainTable[i].Topics);
        }
        i++;
    }
    return doubleNewTable;
}
int linearHashing(struct Course linearMainTable[],char key1[]) {//linear hash used to find the correct index for the node
    unsigned long long int hashValue = 0;//hash value for the string
    char* key=key1;
    while (*key != '\0') {//calculate the hash value
        hashValue = (hashValue << 5) +
                    *key++;
    }
    int index = (int)(hashValue%linearTableSize);//index equal to the hash value (reminder) the table sze
    int i = 0;

    while (strcmp(linearMainTable[index].CourseName, "\0") != 0) {//if the index is not null
        i++;
        index = (hashValue + i) % linearTableSize;//find new index

        if(i==linearTableSize){
            return -1;
        }
    }
    linearNumberOfCollision=linearNumberOfCollision+i;//count collisions
    return index;
}
int doubleHashing(struct Course doubleMainTable[],char * key){//double hash used to find the correct index for the node
    int valueOfSecHash;//h2(x)
    unsigned long long int  hashValue = 0;//hash value for the string
    while( *key != '\0'){//calculate the hash value
        hashValue = ( hashValue << 5 ) +
                    *key++;
    }
    int i = 0;
    //find h2(x)=R(X%R) while R is first prime number before table size and X is hash value of the string
    valueOfSecHash= (int)(findFirstPrimeBefore(doubleTableSize)-(hashValue% findFirstPrimeBefore(doubleTableSize)));
    //H(x)=h1(x)+i*h2(x)
    int index=(int)(hashValue%doubleTableSize+i*valueOfSecHash)%doubleTableSize;


    while (strcmp(doubleMainTable[index].CourseName, "\0") != 0) {//if the index is not null
        i++;
        index =(int)(hashValue%doubleTableSize+i*valueOfSecHash)%doubleTableSize;//find new index
    }
    doubleNumberOfCollision=doubleNumberOfCollision+i;//count collisions
    return index;
}
struct Course* linearMakeEmpty(struct Course linearMainTable []){//clean the table
    int i=0;
    while(i<linearTableSize){
        strcpy(linearMainTable[i].CourseName,"\0");
        linearMainTable[i].CreditHours=0;
        strcpy(linearMainTable[i].CourseCode,"\0");
        strcpy(linearMainTable[i].Department,"\0");
        strcpy(linearMainTable[i].Topics,"\0");
        i++;
    }
    return linearMainTable;
}
struct Course* doubleMakeEmpty(struct Course doubleMainTable []){//clean the table
    int i=0;
    while(i<doubleTableSize){
        strcpy(doubleMainTable[i].CourseName,"\0");
        doubleMainTable[i].CreditHours=0;
        strcpy(doubleMainTable[i].CourseCode,"\0");
        strcpy(doubleMainTable[i].Department,"\0");
        strcpy(doubleMainTable[i].Topics,"\0");
        i++;
    }
    return doubleMainTable;
}
struct Course* linearInsert(struct Course linearMainTable[],char CourseNameN [50], int CreditHoursN,char CourseCodeN [30],char DepartmentN [50], char TopicsN [150]){//insert new node to the linear table
    int val= linearHashing(linearMainTable,CourseNameN);//get the index
    //copy data
    strcpy(linearMainTable[val].CourseName, CourseNameN);
    linearMainTable[val].CreditHours = CreditHoursN;
    strcpy(linearMainTable[val].CourseCode, CourseCodeN);
    strcpy(linearMainTable[val].Department, DepartmentN);
    strcpy(linearMainTable[val].Topics, TopicsN);
    linearUsedCells++;//increase the cells used
    if (isOdd(linearTableSize) == 0) {
        if (linearUsedCells >= linearTableSize / 2) {//if the used cells is equal or more to half of the table
            linearMainTable=linearRehash(linearMainTable);//rehash
            return linearMainTable;
        }
        return linearMainTable;
    }

    if (isOdd(linearTableSize) == 1) {
        if (linearUsedCells >= (linearTableSize / 2)+1) {//if the used cells is equal or more to half of the table
            linearMainTable=linearRehash(linearMainTable);//rehash
            return linearMainTable;

        }
        return linearMainTable;
    }
    linearInsertNew(linearNewTable,CourseNameN,CreditHoursN,CourseCodeN,DepartmentN,TopicsN);//insert into the global table
    return linearMainTable;
}
struct Course* doubleInsert(struct Course doubleMainTable[],char CourseNameN [50], int CreditHoursN,char CourseCodeN [30],char DepartmentN [50], char TopicsN [150]){//insert new node to the double table
    int val= doubleHashing(doubleMainTable,CourseNameN);//get the index
    //copy data
    strcpy(doubleMainTable[val].CourseName, CourseNameN);
    doubleMainTable[val].CreditHours = CreditHoursN;
    strcpy(doubleMainTable[val].CourseCode, CourseCodeN);
    strcpy(doubleMainTable[val].Department, DepartmentN);
    strcpy(doubleMainTable[val].Topics, TopicsN);
    doubleUsedCells++;
    if (isOdd(doubleTableSize) == 0) {
        if (doubleUsedCells >= doubleTableSize / 2) {//if the used cells is equal or more to half of the table
            doubleMainTable=doubleRehash(doubleMainTable);//rehash
            return doubleMainTable;
        }
        return doubleMainTable;
    }

    if (isOdd(doubleTableSize) == 1) {
        if (doubleUsedCells >= (doubleTableSize / 2)+1) {//if the used cells is equal or more to half of the table
            doubleMainTable=doubleRehash(doubleMainTable);//rehash
            return doubleMainTable;

        }
        return doubleMainTable;
    }
    doubleInsertNew(doubleNewTable,CourseNameN,CreditHoursN,CourseCodeN,DepartmentN,TopicsN);//insert into the global table
    return doubleMainTable;
}
struct Course* linearInsertNew(struct Course* linearMainTable,char CourseNameN [50], int CreditHoursN,char CourseCodeN [30],char DepartmentN [50], char TopicsN [150]){//used to transform data in rehash
    int val= linearHashing(linearMainTable,CourseNameN);//get index
    //copy data
    strcpy(linearMainTable[val].CourseName, CourseNameN);
    linearMainTable[val].CreditHours = CreditHoursN;
    strcpy(linearMainTable[val].CourseCode, CourseCodeN);
    strcpy(linearMainTable[val].Department, DepartmentN);
    strcpy(linearMainTable[val].Topics, TopicsN);
    return linearMainTable;
}
struct Course* doubleInsertNew(struct Course* doubleMainTable,char CourseNameN [50], int CreditHoursN,char CourseCodeN [30],char DepartmentN [50], char TopicsN [150]){//used to transform data in rehash
    int val= doubleHashing(doubleMainTable,CourseNameN);//get index
    //copy data
    strcpy(doubleMainTable[val].CourseName, CourseNameN);
    doubleMainTable[val].CreditHours = CreditHoursN;
    strcpy(doubleMainTable[val].CourseCode, CourseCodeN);
    strcpy(doubleMainTable[val].Department, DepartmentN);
    strcpy(doubleMainTable[val].Topics, TopicsN);
    return doubleMainTable;
}
struct Course* fileReader(struct Course linearMainTable[],struct Course doubleMainTable[] ){//read file and load data in the tables
    FILE *fileReader;//file pointer
    fileReader= fopen("offered_courses.txt","r");//open file in read mode
    if(fileReader==NULL){
        printf("error while reading file\n");
        return linearMainTable;
    }
    else{
        char courseRead [250];
        int count=0;
        while( fgets(courseRead,sizeof (courseRead),fileReader)!=NULL){//read line by line
            count++;
            char CourseNameN [50] ;
            int CreditHoursN;
            char CourseCodeN [30];
            char DepartmentN [50];
            char TopicsN [150];
            //trim
            char *token= strtok(courseRead,":");
            //copy data
            strcpy(CourseNameN,token);
            token= strtok(NULL,"#");
            CreditHoursN= atoi(token);
            token= strtok(NULL,"#");
            strcpy(CourseCodeN,token);
            token= strtok(NULL,"/");
            strcpy(DepartmentN,token);
            token= strtok(NULL,"\n");
            strcpy(TopicsN,token);
            linearMainTable=linearInsert(linearMainTable,CourseNameN,CreditHoursN,CourseCodeN,DepartmentN,TopicsN);//insert into linear table
            doubleMainTable=doubleInsert(doubleMainTable,CourseNameN,CreditHoursN,CourseCodeN,DepartmentN,TopicsN);//insert into double table

        }

    }
    return linearMainTable;
}
int linearglobalIndex=0;
int deleteMoreCase1=0;
char deleteMoreCase[50]="\0";
struct Course linearSearch(struct Course linearMainTable[],char CourseNameN [50] ){//to search for a node by its name

    char *temp=CourseNameN;
    unsigned long long int hashValue = 0;
    while (*temp != '\0') {//calculate the hash value
        hashValue = (hashValue << 5) +
                    *temp++;
    }
    int index ;//find the index
    int count=0;
    int c=0;
    int index2;
    int arrayIndex [1000];
    while (c<linearTableSize) {//count how much same name
        index = (int)((hashValue+c)%linearTableSize);
        if(strcmp(linearMainTable[index].CourseName,CourseNameN)==0){
            arrayIndex[count]=index;
            count++;
            index2=index;

        }
        c++;
    }
    if(count ==0){
        printf ("the course not found please try again\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        struct Course notFound={"\0",0,"\0","\0","\0"};
        return notFound;
    }
    if(count ==1){
        linearglobalIndex=index2;
        return linearMainTable[index2];
    }
    if(count >1){

        int a=0;
        printf("there are more than one course by this name,please enter the code you need\n");
        while (a<count){
            printf("%s\t",linearMainTable[arrayIndex[a]].CourseCode);
            a++;
        }
        printf("\n");
        char code [50];
        fflush(stdin);
        printf("enter the course code to search for it\n");
        scanf("%[a-z,A-Z,0-9,' ']c",code);
        if(deleteMoreCase1==1){
            strcpy(deleteMoreCase,code);
        }
        int b=0;
        while(b<count){
            if(strcmp(linearMainTable[arrayIndex[b]].CourseCode,code)==0){
                linearglobalIndex=arrayIndex[b];
                return linearMainTable[arrayIndex[b]];
            }
            b++;
        }
    }
}
void linearPrintCourse(struct Course linearMainTable []){
    char CourseNameN [50];
    fflush(stdin);
    printf("enter the course name to search for it\n");
    scanf("%[a-z,A-Z,0-9,' ']c",CourseNameN);
    struct Course new;
    new= linearSearch( linearMainTable ,CourseNameN);
    if(strcmp(new.CourseName,"\0")==0){
        return;
    }

    printf("the Course %s is in index %d\n",CourseNameN,linearglobalIndex);
    printf("name: %s\n",linearMainTable[linearglobalIndex].CourseName);
    printf("hours: %d\n",linearMainTable[linearglobalIndex].CreditHours);
    printf("code: %s\n",linearMainTable[linearglobalIndex].CourseCode);
    printf("Department: %s\n",linearMainTable[linearglobalIndex].Department);
    printf("topics: %s\n",linearMainTable[linearglobalIndex].Topics);

    printf("------------------------------------------------------------------------------------------------------------------------\n");

}
int doubleglobalIndex=0;
struct Course doubleSearch(struct Course doubleMainTable[],char CourseNameN [50] ){//to search for a node by its name
    char *temp=CourseNameN;
    int valueOfSecHash;
    unsigned long long int  hashValue = 0;
    while( *temp != '\0'){//calculate the hash value
        hashValue = ( hashValue << 5 ) +
                    *temp++;
    }
    int i = 0;
    //find the index
    valueOfSecHash= findFirstPrimeBefore(doubleTableSize)-(hashValue% findFirstPrimeBefore(doubleTableSize));

    int index ;//find the index
    int count=0;
    int c=0;
    int index2;
    int arrayIndex [1000];
    while (c<doubleTableSize) {//count how much same name
        index=(int)(hashValue%doubleTableSize+c*valueOfSecHash)%doubleTableSize;
        if(strcmp(doubleMainTable[index].CourseName,CourseNameN)==0){
            arrayIndex[count]=index;
            count++;
            index2=index;

        }
        c++;
    }
    if(count ==0){
        printf ("the course not found please try again\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        struct Course notFound={"\0",0,"\0","\0","\0"};
        return notFound;
    }
    if(count ==1){
        doubleglobalIndex=index2;
        return doubleMainTable[index2];
    }
    if(count >1){
        char code [50];
        if(deleteMoreCase1==0) {
            int a=0;
            printf("there are more than one course in double table by this name,please enter the code you need\n");
            while (a<count){
                printf("%s\t",doubleMainTable[arrayIndex[a]].CourseCode);
                a++;
            }
            printf("\n");
            fflush(stdin);
            printf("enter the course code to search for it\n");
            scanf("%[a-z,A-Z,0-9,' ']c", code);
        }
        if(deleteMoreCase1==1){
            strcpy(code,deleteMoreCase);
        }
        int b=0;
        while(b<count){
            if(strcmp(doubleMainTable[arrayIndex[b]].CourseCode,code)==0){
                doubleglobalIndex=arrayIndex[b];
                return doubleMainTable[arrayIndex[b]];
            }
            b++;
        }
    }

}
void doublePrintCourse(struct Course doubleMainTable []){
    char CourseNameN [50];
    fflush(stdin);
    printf("enter the course name to search for it\n");
    scanf("%[a-z,A-Z,0-9,' ']c",CourseNameN);
    struct Course new;
    new= doubleSearch( doubleMainTable ,CourseNameN);
    if(strcmp(new.CourseName,"\0")==0){
        return;
    }

    printf("the Course %s is in index %d\n",CourseNameN,doubleglobalIndex);
    printf("name: %s\n",doubleMainTable[doubleglobalIndex].CourseName);
    printf("hours: %d\n",doubleMainTable[doubleglobalIndex].CreditHours);
    printf("code: %s\n",doubleMainTable[doubleglobalIndex].CourseCode);
    printf("Department: %s\n",doubleMainTable[doubleglobalIndex].Department);
    printf("topics: %s\n",doubleMainTable[doubleglobalIndex].Topics);

    printf("------------------------------------------------------------------------------------------------------------------------\n");

}
struct Course* linearDelete(struct Course linearMainTable[],struct Course doubleMainTable[]){//delete from linear table
    char CourseNameN [50];
    fflush(stdin);
    printf("enter the course name to search for it\n");
    scanf("%[a-z,A-Z,0-9,' ']c",CourseNameN);
    struct Course new;
    deleteMoreCase1=1;
    new= linearSearch( linearMainTable ,CourseNameN);
    if(strcmp(new.CourseName,"\0")==0){
        return linearMainTable;
    }
    printf("deleting the course %s from index %d in linear table\n",CourseNameN,linearglobalIndex);
    strcpy(linearMainTable[linearglobalIndex].CourseName,"\0");
    linearMainTable[linearglobalIndex].CreditHours=0;
    strcpy(linearMainTable[linearglobalIndex].CourseCode,"Empty");
    strcpy(linearMainTable[linearglobalIndex].Department,"\0");
    strcpy(linearMainTable[linearglobalIndex].Topics,"\0");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    doubleDelete( doubleMainTable, CourseNameN);


}

struct Course* doubleDelete(struct Course doubleMainTable[],char CourseNameN [50]){
    struct Course new;
    new= doubleSearch( doubleMainTable ,CourseNameN);
    if(strcmp(new.CourseName,"\0")==0){
        return doubleMainTable;
    }
    printf("deleting the course %s from index %d in double table\n",CourseNameN,doubleglobalIndex);
    strcpy(doubleMainTable[doubleglobalIndex].CourseName,"\0");
    doubleMainTable[doubleglobalIndex].CreditHours=0;
    strcpy(doubleMainTable[doubleglobalIndex].CourseCode,"\0");
    strcpy(doubleMainTable[doubleglobalIndex].Department,"\0");
    strcpy(doubleMainTable[doubleglobalIndex].Topics,"\0");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

}
int isPrime(int num){//check if the number is prime or not
    if(num==1||num==2){//if 1 or 2 its prime
        return 1;
    }
    int count=0, number=2;
    while (number<num){//count how many numbers is dividable
        if(num%number==0){
            count++;
            number++;
        }
        number++;
    }
    if(count==0){//if prime
        return 1;
    }
    return 0;//if not
}
int findFirstPrimeBefore(int doubleSize){//to find first prime before the table size
    int temp=doubleSize;
    temp--;
    while (temp>0){//wile not zero
        if(isPrime(temp)==1){//if prime
            return temp;
        }
        temp--;
    }
    return temp;
}
int findFirstPrimeAfter(){//to find the first prime number after the double of table current size
    int temp=linearTableSize*2;//double it
    temp++;
    while (temp>0){
        if(isPrime(temp)==1){//if prime
            return temp;
        }
        temp++;
    }
    return temp;
}
int isOdd(int num){//check if a number is odd or not
    return num%2;
}
void printAll(struct Course linearMainTable[]){//print all data in the table(not used )
    int c=0;
    while(c<linearTableSize){
        printf("in index %d\n\n",c);
        printf("name: %s\n",linearMainTable[c].CourseName);
        printf("hours: %d\n",linearMainTable[c].CreditHours);
        printf("code: %s\n",linearMainTable[c].CourseCode);
        printf("dep: %s\n",linearMainTable[c].Department);
        printf("topics: %s\n",linearMainTable[c].Topics);
        printf("---------------------------------------------------------------\n\n");
        c++;
    }
}
int doubleFindFirstPrimeAfter(){//to find the first prime number after the double of table current size
    int temp=doubleTableSize*2;//double it
    temp++;
    while (temp>0){
        if(isPrime(temp)==1){//if prime
            return temp;
        }
        temp++;
    }
    return temp;
}
struct Course* doubleInsertCall(struct Course doubleMainTable[], char CourseNameN [50], int CreditHoursN,char CourseCodeN [30],char DepartmentN [50],char  TopicsN [150]){//calling of double insert function
    int index= doubleHashing(doubleNewTable,CourseNameN);//find the index
    //copy data
    strcpy(doubleNewTable[index].CourseName, CourseNameN);
    doubleNewTable[index].CreditHours = CreditHoursN;
    strcpy(doubleNewTable[index].CourseCode, CourseCodeN);
    strcpy(doubleNewTable[index].Department, DepartmentN);
    strcpy(doubleNewTable[index].Topics, TopicsN);
    doubleUsedCells++;//increase used cells
    printf("added at index %d to double table\n",index);
    if (isOdd(doubleTableSize) == 0) {
        if (doubleUsedCells >= doubleTableSize / 2) {//if table need to rehash

            doubleNewTable=doubleRehash(doubleNewTable);
            return doubleNewTable;
        }
        return doubleNewTable;
    }

    if (isOdd(doubleTableSize) == 1) {
        if (doubleUsedCells >= (doubleTableSize / 2)+1) {//if table need to rehash
            doubleNewTable=doubleRehash(doubleNewTable);
            return doubleNewTable;

        }
        return doubleNewTable;
    }

    printf("course added successfully\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}
struct Course* insertCall(struct Course linearMainTable[],struct Course doubleMainTable[]){//calling of double insert function
    //read data
    char CourseNameN [50];
    int CreditHoursN;
    char CourseCodeN [30];
    char DepartmentN [50];
    char  TopicsN [150];
    printf("------------------------------------------------------------------------------------------------------------------------");
    fflush(stdin);
    printf("enter Course name\n");
    scanf("%[a-z,A-Z,0-9,' ']c",CourseNameN);
    fflush(stdin);
    printf("enter credit hours\n");
    scanf("%d",&CreditHoursN);
    fflush(stdin);
    printf("enter the course code\n");
    scanf("%[a-z,A-Z,0-9,' ']c",CourseCodeN);
    fflush(stdin);
    printf("enter the department\n");
    scanf("%[a-z,A-Z,0-9,' ']c",DepartmentN);
    fflush(stdin);
    printf("enter the topics and put (,) between\n");
    scanf("%[a-z,A-Z,0-9,' ']c",TopicsN);

    int index= linearHashing(linearNewTable,CourseNameN);//find index
    //copy data
    strcpy(linearNewTable[index].CourseName, CourseNameN);
    linearNewTable[index].CreditHours = CreditHoursN;
    strcpy(linearNewTable[index].CourseCode, CourseCodeN);
    strcpy(linearNewTable[index].Department, DepartmentN);
    strcpy(linearNewTable[index].Topics, TopicsN);
    linearUsedCells++;//increase used cells
    doubleNewTable=doubleInsertCall(  doubleNewTable,  CourseNameN ,  CreditHoursN, CourseCodeN , DepartmentN ,  TopicsN );//insert in double table
    if (isOdd(linearTableSize) == 0) {
        if (linearUsedCells >= linearTableSize / 2) {//if table need to rehash

            linearNewTable=linearRehash(linearNewTable);
            printf("at index %d on linear table\n"
                   "course added successfully \n",index);
            printf("------------------------------------------------------------------------------------------------------------------------\n");

            return linearNewTable;
        }
        printf("at index %d on linear table\n"
               "course added successfully \n",index);
        printf("------------------------------------------------------------------------------------------------------------------------\n");

        return linearNewTable;
    }

    if (isOdd(linearTableSize) == 1) {
        if (linearUsedCells >= (linearTableSize / 2)+1) {//if table need to rehash
            linearNewTable=linearRehash(linearNewTable);
            printf("at index %d on linear table\n"
                   "course added successfully \n",index);
            printf("------------------------------------------------------------------------------------------------------------------------\n");

            return linearNewTable;

        }
        printf("at index %d on linear table\n"
               "course added successfully \n",index);
        printf("------------------------------------------------------------------------------------------------------------------------\n");

        return linearNewTable;
    }

}
void PrintOnFileCall(){//print the data in the double table in the file
    FILE *FileWriter;//file pointer
    FileWriter= fopen("saved_courses.txt","w");//open file in write mode
    int x=0;
    while(x<doubleTableSize){//while less than size
        if(strcmp(doubleNewTable[x].CourseName,"\0")!=0){//if not null
            //print in the file
            fprintf(FileWriter,"%s:%d#%s#%s/%s\n",doubleNewTable[x].CourseName,doubleNewTable[x].CreditHours,doubleNewTable[x].CourseCode,doubleNewTable[x].Department,doubleNewTable[x].Topics);
        }
        x++;
    }
    fclose(FileWriter);//close the file
    printf("print in the file done successfully\n");
    printf("------------------------------------------------------------------------------------------------------------------------");


}