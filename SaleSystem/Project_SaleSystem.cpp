#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <windows.h>

using namespace std;


bool MainLogin();
bool Login();
bool Register();

void CheckStock(int stockDefault[3][4], int stock[3][4], string product[3][4], float pricePPU[3][4]);
void UpdateID(int &OrderID, int &CustomerID);

void CustomerData(int CustomerID);
void Sell(float pricePPU[3][4], int &OrderID, int stock[3][4], int stockDefault[3][4], string product[3][4], int &CustomerID, bool &Update);
void Cart(int amountItem, int OrderID, string cartProduct[24], int cartAmount[24], float cartPrice[24]);
void Stock(float pricePPU[3][4], int stock[3][4], string product[3][4]);
void Report(int CustomerID, int OrderID, bool Update);

void NoData();
void NotFound(string type);
bool DateFormat_Check(string checkDate);
bool NameFormat_Check(string Name, string type);
bool EmailFormat_Check(string emailCheck);


// ##################### CONFIG #####################   ตั้งค่าตัวแปร ชื่อไฟล์ และโฟลเดอร์ต่างๆได้

string FolderName = "Database";                     // ชื่อโฟลเดอร์หลัก
string CustomerFolder = "Customer";                 // ชื่อโฟลเดอร์เก็บข้อมูลและการสั่งซื้อสินค้าของลูกค้า
string DailyFolder = "DailyOrders";                 // ชื่อโฟลเดอร์เก็บข้อมูลการสั่งซื้อแต่ละวัน

const string AccountFile = "Account.dat";           // ไฟล์เก็บข้อมูลและการสั่งซื้อสินค้าของลูกค้า
const string StockFile = "Stock.dat";               // ไฟล์เก็บข้อมูลสินค้า
const string DailyLog = "Daily.dat";                // ไฟล์เก็บข้อมูลวันที่มีการซื้อสินค้า
const string ID_File = "LastID.dat";                // ไฟล์เก็บรหัสลูกค้าและจำนวนออเดอร์

const string Path = FolderName+"/";                 // ใช้สำหรับการเข้าโฟลเดอร์หลัก
const string CustomerPath = CustomerFolder+"/";     // ใช้สำหรับการเข้าโฟลเดอร์เก็บข้อมูลการสั่งซื้อแต่ละวัน
const string DailyPath = DailyFolder+"/";           // ใช้สำหรับการเข้าโฟลเดอร์เก็บข้อมูลการสั่งซื้อแต่ละวัน

float vat = 3.0;        // ภาษีมูลค่าเพิ่ม หน่วยเปอร์เซ็นต์

string CategoryList[]  = {"Shirt Category", "Pants Category", "Shoes Category"};                        // ชื่อหมวดหมู่สินค้า
string ProductAdd[][4] = {  {"T-Shirt", "Shirt", "Jacket", "Suit"},                                     // ชื่อสินค้า
                            {"Shorts", "Trousers", "Jeans", "Skirt"},                                  
                            {"Sneaker", "Sandals", "High-heels", "Boots"}};                             
float PriceAdd[][4]    = {{100, 150, 200, 1000}, {100, 175, 625, 150}, {350, 125, 325, 125}};           // ราคาสินค้า


//#############################################################################
//-------------------------------     MAIN     -------------------------------
//#############################################################################

int main()
{   
    bool Update=true;
    int OrderID, CustomerID;
    int stockDefault[3][4], stock[3][4];
    float pricePPU[3][4];
    string  product[3][4];

    // สร้างโฟล์เดอร์จัดเก็บข้อมูล
    string sysOut = "mkdir "+FolderName+" && cd "+FolderName+" && md "+CustomerFolder+" "+DailyFolder;
    const char *cmd = sysOut.c_str();
    system(cmd);
    system("cls");

    CheckStock(stockDefault, stock, product, pricePPU);     // เช็คและอัพเดตสต็อค
    UpdateID(OrderID, CustomerID);                          // เช็คและอัพเดตรหัสลูกค้า จำนวนออเดอร์

    bool Main = MainLogin();    // เข้าเมนูล็อคอิน
    if (Main)
    {
        char menu, exit;
        do
        {

            cout << "======== Online Sales ========\n" << endl;
            cout << "1) Sell Product" << endl;
            cout << "2) Warehouse Management" << endl;
            cout << "3) Customer Data Management" << endl;
            cout << "4) Dialy Report" << endl;
            cout << "0) Logout" << endl;
            cout << "X) Exit Program" << endl;
            cout << "\n" << setfill('=') << setw(31) << " " << endl << endl;
            cout << "Choose menu : ";
            cin >> menu;
            BlockInput(TRUE);
            menu = toupper(menu);

            switch (menu)
            {   
                case '1':
                    system("cls");
                    BlockInput(FALSE);
                    Sell(pricePPU, OrderID, stock, stockDefault, product, CustomerID, Update);
                    system("cls");
                    break;

                case '2':
                    system("cls");
                    BlockInput(FALSE);
                    Stock(pricePPU, stock, product);
                    cout << endl;
                    system("pause");
                    system("cls");
                    break;

                case '3':
                    system("cls");
                    BlockInput(FALSE);
                    CustomerData(CustomerID);
                    system("cls");
                    break;
                    
                case '4':
                    system("cls");
                    BlockInput(FALSE);
                    Report(CustomerID, OrderID, Update);
                    system("cls");
                    break;

                case '0':
                    system("cls");
                    BlockInput(FALSE);
                    Login();
                    break;

                case 'X':
                    cout << "\nAre you sure to exit?\n";
                    cout << "Press \'Y\' to confirm or \'N\' to cancel : ";
                    cin >> exit;
                    BlockInput(TRUE);
                    exit = toupper(exit);
                    system("cls");
                    break;
                
                default:
                    cout << "\nInvalid menu, please try again.";
                    BlockInput(TRUE);
                    Sleep(2500);
                    BlockInput(FALSE);
                    system("cls");
            }
        } while (exit!='Y');
    }
    
    system("cls");
    cout << "Exiting Program ...\n\n";
    Sleep(1000);
    for (int i=0; i<3; i++)
    {
        cout << ".\n";
        Sleep(800);
    }
    Sleep(200);
    cout << "Exit!\n";
    Sleep(800);

    
    cout << endl;
    system("pause");
    return 0;
}


//#############################################################################
//                          CUSTOMER DATA MENAGEMENT                                ระบบการจัดการข้อมูลลูกค้า
//#############################################################################


void CustomerData(int CustomerID)
{
    string checkID;
    string line, head, colon, fName, lName, email;


    while (checkID!="0")
    {
        cout << "Customer Data Management\n\n";

        if (CustomerID>1)       // ถ้ารหัสลูกค้ามากกว่า 1 จะโชว์รหัสลูกค้าทั้งหมด และสามารถเข้าไปดูรายละเอียดได้
        {
            int emailLenght=0, nameLenght=0;

            for (int i=1; i<=CustomerID; i++)
            {
                const string CustomerFind = "C" + string((i<100)?((i<10)?"00":"0"):"") + to_string(i) + ".dat";

                ifstream InCustomer(Path+CustomerPath+CustomerFind.c_str(), ios_base::in);
                if (InCustomer.is_open())
                {
                    for (int i=0; i<3; i++)
                        getline(InCustomer, line);
                    istringstream LenghtName(line);

                    LenghtName >> head >> colon >> fName >> lName;
                    if (nameLenght < (fName+" "+lName).length())
                        nameLenght = (fName+" "+lName).length();

                    InCustomer >> head >> colon >> email;
                    if (emailLenght < email.length())
                        emailLenght = email.length();
                }
                InCustomer.close();
            }
            
            string lineEq(12+nameLenght+emailLenght, '='), lineD(12+nameLenght+emailLenght, '-');

            cout << lineEq << endl;
            cout << "ID  \t" << left << setfill(' ') << setw(nameLenght+4) << "Name" << "Email\n";
            cout << lineD << endl;


            for (int i=1; i<=CustomerID; i++)
            {
                const string CustomerList = "C" + string((i<100)?((i<10)?"00":"0"):"") + to_string(i) + ".dat";

                ifstream InCustomerList(Path+CustomerPath+CustomerList.c_str(), ios_base::in);
                if (InCustomerList.is_open())
                {
                    for (int i=0; i<3; i++)
                        getline(InCustomerList, line);
                    istringstream CustomerName(line);

                    CustomerName >> head >> colon >> fName >> lName;
                    cout << left << setfill(' ') << setw(4) <<"C"+string((i<100)?((i<10)?"00":"0"):"")+to_string(i);
                    cout << "\t" << setw(nameLenght+4) << fName+" "+lName;
                    InCustomerList >> head >> colon >> email;
                    cout << email << endl;
                }
                InCustomerList.close();
            }
            
            // ป้อนรหัาลูกค้าที่ต้องการดูรายละเอียด
            cout << endl << lineEq << endl;
            cout << "\n(0=Exit)";
            cout << "\nInput Customer ID : C";
            cin >> checkID;
            BlockInput(TRUE);

            // เช็คว่าใส่เลขถูกต้องหรือไม่
            for (int i=0; i<checkID.length(); i++)
            {
                if (!isdigit(checkID[i]))
                {
                    checkID="0";
                    break;
                }
            }

            if (checkID!="0" && checkID.length()<=3)
            {
                Sleep(800);
                cout << "\nSearching ";
                for(int i=0; i<3; i++)
                {
                    Sleep(500);
                    cout << ".";
                }
                Sleep(2000);
                system("cls");
                
                const string CustomerInfo = "C" + string((stoi(checkID)<100)?((stoi(checkID)<10)?"00":"0"):"") + to_string(stoi(checkID)) + ".dat";

                // นำรหัสลูกค้าที่ป้อนไปค้นค้าชื่อไฟล์ หากเจอชื่อจะแสดงข้อมูลลูกค้า รายการสินค้าที่ซื้อ และยอดรวมสั่งซื้อ
                ifstream InCustomerInfo(Path+CustomerPath+CustomerInfo.c_str(), ios_base::in);
                if (InCustomerInfo.is_open())
                {
                    int qty, index=0, totalQty[12]={0};
                    float itemPrice, totalPrice=0, price[12], totalPurchase;
                    string lineText, item, product[12], lineEq(32,'=');


                    InCustomerInfo >> lineText;
                    for (int i=0; i<3; i++)
                        getline(InCustomerInfo, line);
                    istringstream CustomerName(line);

                    CustomerName >> head >> colon >> fName >> lName;
                    cout << left << setw(10) << "Custommer ID : C" + string((stoi(checkID)<100)?((stoi(checkID)<10)?"00":"0"):"") + to_string(stoi(checkID)) << endl;
                    cout << "Name  : " << fName+" "+lName << endl;
                    InCustomerInfo >> head >> colon >> email;
                    cout << "Email : " << email << endl;
                    cout << lineEq << endl;
                    cout << setw(14) << setfill(' ') << "Product" << right << setw(8) << "P/U" << setw(10) << "Qty."<< endl;
                    cout << setfill ('-') << setw(32) << "" << setfill(' ') << endl;

                    for (int i=0; i<5; i++)
                        getline(InCustomerInfo, line);

                    while (InCustomerInfo >> item >> itemPrice >> qty)
                    {
                        bool duplicateItem=false;
                        for (int i=0; i<sizeof(product)/sizeof(product[0]); i++)
                        {
                            if (item==product[i])
                            {
                                duplicateItem = true;
                                totalQty[i] += qty;
                                break;
                            }
                        }

                        if (!duplicateItem)
                        {
                            product[index] = item;
                            price[index] = itemPrice;
                            totalQty[index] += qty;
                            index++;
                        }                        
                    }

                    for (int i=0; i<index; i++)
                    {
                        cout << left << setw(14) << product[i] << right << setw(8) << fixed << setprecision(2) << price[i] << setprecision(0) << setw(9) << totalQty[i] << endl;
                        totalPrice += price[i]*totalQty[i];        
                    }
                    totalPurchase = totalPrice+(totalPrice*(vat/100.0));

                    cout << endl << setfill(' ') << setw(20) << right << "Total : " << right << setw(13-(to_string(totalPurchase).length()-3)) << "$" << setprecision(2) << totalPurchase << setprecision(0) << endl;
                    cout << lineEq << endl << endl;
                }
                else
                    NotFound("ID");     // ถ้าไม่เจอจะแสดงผลว่าไม่พบรหัสลูกค้าที่ป้อน
                InCustomerInfo.close();

                BlockInput(FALSE);
                system("pause");
                system("cls");
            }
            else
                system("cls");      // หากกด 0 จะออกจากเมนู
        }
        else
        {
            NoData();   // ถ้ารหัสลูกค้าเป็น 1 หรือน้อยกว่าจะไม่มีข้อมูลลูกค้าแสดง
            break;
        }
    }
}


//#############################################################################
//                                 DAILY REPORT                                     รายงานการสั่งซื้อแต่ละวัน
//#############################################################################


void Report(int CustomerID, int OrderID, bool Update)
{
    // จะอัพเดตทุกทั้งที่ซื้อสินค้าเสร็จ เพื่อจะได้เห็นข้อมูลล่าสุด
    if (!Update)
        CustomerID += 1;

    const int size = CustomerID;
    bool format=false, exit=false;
    int duplicate[size], count[size];
    float totalSale[size];
    string checkDate, dateList[size];

    
    if (CustomerID>1)
    {
        // อ่านไฟล์บันทึกยอดขายแต่ละวัน เพื่อเอามาเก็บไว้
        ifstream InLog(Path+DailyLog.c_str(), ios_base::in);
        if (InLog.is_open())
        {
            int index=0;
            float Sale;
            string line, Date;

            getline(InLog, line), getline(InLog, line);
            while (InLog >> Date >> Sale)
            {
                dateList[index] = Date;
                totalSale[index] = Sale;
                index++;
            }
        }
        else
            cout << DailyLog << " : not accessible\nUnable to access daily log file." << endl;


        // เปรียบเทียบว่าถ้าหากซ้ำกันจะแสดงแต่อันเดียว
        for (int i=0; i<CustomerID; i++)
            count[i] = 1;

        for (int i=0; i<size-1; i++)
        {
            for (int k=1; k<size-i; k++)
            {
                if (dateList[i]==dateList[k+i])
                {
                    duplicate[k+i] = k+i;
                    totalSale[i] += totalSale[k+i];
                    count[i]++;
                }
            }
        }

        // แสดงวันที่ จำนวนออเดอร์ของแต่ละวัน และยอดขายรวม
        while (!exit)
        {
            do {
                system("cls");
                cout << "Daily Report\n\n";

                cout << setfill('=') << setw(38) << " " << setfill(' ') << endl;
                cout << "   Date" << right << setw(13) << "Order" << setw(16) << "Total Sale" << endl;
                cout << setfill('=') << setw(38) << " " << setfill(' ') << endl;
                for (int i=0; i<size-1; i++)
                {
                    if (i!=duplicate[i] || i==0)
                    {
                        cout << " " << dateList[i] << right << setw(10) << count[i] << right << setw(17) << fixed << setprecision(2) << totalSale[i] << setprecision(0) << endl;
                    }

                }
                cout << setfill('-') << setw(38) << " " << setfill(' ') << endl;

                // ป้อนวันที่เพื่อดูรายละเอียดเพิ่มเติม
                cout << "\n(0=Exit)";
                cout << "\nInput Date (dd/mm/yy): ";
                cin >> checkDate;
                BlockInput(TRUE);
                if (checkDate!="0")
                    format = DateFormat_Check(checkDate);

            } while (checkDate!="0" && !format);


            if (checkDate!="0")
            {
                Sleep(800);
                cout << "\nSearching ";
                for(int i=0; i<3; i++)
                {
                    Sleep(500);
                    cout << ".";
                }
                cout << "\n\n";
                Sleep(2000);
                system("cls");

                // ค้นหาไฟล์จากวันที่ที่ป้อน
                const int amountItem = OrderID;
                int totalQty[amountItem], duplicateItem[amountItem]={OrderID};
                string allProduct[amountItem];

                // หากเจอจะเปิดไฟล์และเก็ยข้อมูลไว้
                checkDate[2] = '_', checkDate[5] = '_';
                const string DateFile = checkDate+".dat";
                ifstream InDaily(Path+DailyPath+DateFile.c_str(), ios_base::in);
                if (InDaily.is_open())
                {
                    int amount=0, qty;
                    string line, Product;

                    getline(InDaily, line), getline(InDaily, line);
                    while (InDaily >> Product >> qty)
                    {
                        allProduct[amount] = Product;
                        totalQty[amount] = qty;
                        amount++;
                    }

                    // หากสินค้าซ้ำกันจะแสดงแค่อันเดียว และแสดงเป็นจำนวนแทน
                    for (int i=0; i<amount; i++)
                    {
                        for (int k=1; k<amount-i; k++)
                        {
                            if (allProduct[i]==allProduct[k+i])
                            {
                                duplicateItem[k+i] = k+i;
                                totalQty[i] += totalQty[k+i];
                            }
                        }
                    }


                    // แสดงรายละเอียดการซื้อของวันที่ที่ป้อน
                    string lineEq(24, '='), lineD(24, '-');
                    checkDate[2] = '/', checkDate[5] = '/';

                    cout << "Sale in : " << checkDate << endl << endl;
                    cout << lineEq << endl;
                    cout << left << setw(14) << "Product" << right << setw(10) << "Qty." << endl;
                    cout << lineEq << endl;
                    for (int i=0; i<amount; i++)
                    {
                        if (i!=duplicateItem[i])
                            cout << left << setw(14) << allProduct[i] << right << setw(9) << totalQty[i] << endl;
                    }
                    cout << lineD << endl << endl;

                    cout << "Total Sale : ";
                    for (int i=0; i<size; i++)
                    {
                        if (checkDate==dateList[i])
                        {
                            
                            cout << right << setw(13-(to_string(totalSale[i]).length()-3)) << "$" << setprecision(2) << totalSale[i] << endl << endl;
                            break;
                        }
                    }
                }
                else
                    cout << DailyFolder << " : not accessible\nUnable to access daily record file." << endl;

                system("pause");
                system("cls");
            }
            else
                exit = true;        // หากกด 0 จะออกจากเมนู
            
        }
    }
    else
    {
        cout << "Daily Report\n\n";
        NoData();   // ถ้ารหัสลูกค้าเป็น 1 หรือน้อยกว่าจะไม่มีข้อมูลลูกค้าแสดง
    }
}


//#############################################################################
//                                 STOCK                                            ระบบคลังสินค้า
//#############################################################################


void Stock(float pricePPU[3][4], int stock[3][4], string product[3][4])
{
    string line(39, '=');

    cout << "Product in stock\n\n";
    cout << line << endl;
    cout << "ID   Specification" << setfill(' ') << setw(12) << "Price" << setfill(' ') << setw(9) <<"Stock" << endl;
    cout << line << endl;

    char ID[] = {'A', 'B', 'C'};
    for (int i=0; i<3; i++)
    {   
        cout << ID[i] << ")   " << CategoryList[i] << endl << endl;     // แสดงหมวดหมู่สินค้า
        
        // แสดงชื่อสินค้า ราคาต่อหน่วย และจำนวนสินค้าในสต็อค
        for(int k=0; k<4; k++)
        {
            cout << " " << k+1 << "   " << left << setw(12) << setfill(' ') << product[i][k];
            cout << right << fixed << setprecision(2) << setw(13) << pricePPU[i][k] << setprecision(0) << setfill(' ') << right << setw(9) << stock[i][k] << setfill(' ') << endl;
        }
        cout << setfill('-') << setw(40) << " " << endl;

    }
}


//#############################################################################
//                                 SELL                                             ระบบขายสินค้า
//#############################################################################


void Sell(float pricePPU[3][4], int &OrderID, int stock[3][4], int stockDefault[3][4], string product[3][4], int &CustomerID, bool &Update)
{
    bool confirm=false, success=false;
    char category;
    int amount, item, categoryID, amountItem=0;
    string firstname, lastname, checkDate, emailCheck;
    int cartAmount[24];
    float cartPrice[24];
    string cartProduct[24]; 
    string name, email, date, ID;


    CheckStock(stockDefault, stock, product, pricePPU);     // จะเช็คสต็อคทุกครั้งเพื่อป้องกัน Error และ สินค้าไม่เพียงพอ

    bool FormatCheck;
    do          // ป้อนชื่อจริง และเช็ครูปแบบว่าถูกต้องมั้ย
    {
        system("cls");
        cout << "==== Customer Info ====\n\n";
        cout << "Firstname : ";
        cin >> firstname;
        BlockInput(TRUE);
        FormatCheck = NameFormat_Check(firstname, "firstname");
        BlockInput(FALSE);
    } while (!FormatCheck);
    do          // ป้อนนามสกุล และเช็ครูปแบบว่าถูกต้องมั้ย
    {
        system("cls");
        cout << "==== Customer Info ====\n\n";
        cout << "Firstname : " << firstname << endl;
        cout << "Lastname : ";
        cin >> lastname;
        BlockInput(TRUE);
        FormatCheck = NameFormat_Check(lastname, "lastname");
        BlockInput(FALSE);
    } while (!FormatCheck);
    name = firstname+" "+lastname;

    do          // ป้อนอีเมล และเช็ครูปแบบว่าถูกต้องมั้ย
    {
        system("cls");
        cout << "==== Customer Info ====\n\n";
        cout << "Firstname : " << firstname << endl;
        cout << "Lastname : " << lastname << endl;
        cout << "Email : ";
        cin >> emailCheck;
        BlockInput(TRUE);
        FormatCheck = EmailFormat_Check(emailCheck);
    } while (!FormatCheck);
    email = emailCheck;
    
    do          // ป้อนวันที่ และเช็ครูปแบบว่าถูกต้องมั้ย อ้างอิงวันที่จาก 11/2023
    {
        system("cls");
        cout << "==== Customer Info ====\n\n";
        cout << "Firstname : " << firstname << endl;
        cout << "Lastname : " << lastname << endl;
        cout << "Email : " << emailCheck << endl;
        cout << "Order date (dd/mm/yy) : ";
        BlockInput(FALSE);
        cin >> checkDate;
        BlockInput(TRUE);
        FormatCheck = DateFormat_Check(checkDate);
        BlockInput(FALSE);
    } while (!FormatCheck);
    date = checkDate;

    UpdateID(OrderID, CustomerID);      // อัพเเดตรหัสลูกค้า และจำนวนออเดอร์
    int LastID = CustomerID;

    bool find=false;
    int findID=1;

    while (!find && CustomerID>1)       // ค้นหาว่าชื่อและนามสกุลที่ป้อนตรงกับฐานข้อมูลลูกค้าเดิมหรือไม่
    {
        const string CustomerFind = "C" + string((findID<100)?((findID<10)?"00":"0"):"") + to_string(findID) + ".dat";

        ifstream InCustomer(Path+CustomerPath+CustomerFind.c_str(), ios_base::in);
        if (InCustomer.is_open())
        {
            string line, head, colon, fName, lName;
            
            for (int i=0; i<3; i++)
                getline(InCustomer, line);
            istringstream checkCustomerName(line);

            checkCustomerName >> head >> colon >> fName >> lName;
            
            if (name == (fName+" "+lName))
            {
                find = true;
                CustomerID = findID;        // หากตรงกันจะใช้รหัสลูกค้าเดิม
            }

            findID++;
        }
        else
        {
            findID++;
        }
        InCustomer.close();

        if (findID==CustomerID)
            break;
    }

    ID = "C" + string((CustomerID<100)?((CustomerID<10)?"00":"0"):"") + to_string(CustomerID);

    while (!success)
    {
        do
        {
            // แสดงสินค้าในคลัง
            system("cls");
            Stock(pricePPU, stock, product);
            
            cout << "\n(Y=Confirm, X=Cancel, T=Cart)\n";        // ป้อน ID ของหมวดหมู่สินค้าที่แสดง เป็นตัวอักษร
            cout << "Choose Category ID : ";
            cin >> category;
            BlockInput(TRUE);
            category = toupper(category);

            if (category=='A')
                categoryID = 0;
            else if (category=='B')
                categoryID = 1;
            else if (category=='C')
                categoryID = 2;
            else if (category=='Y')     // ถ้ากด Y จะเป็นการยืนยันคำสั่งซื้อ
            {
                if (amountItem>0)
                {
                    char warnConfirm;

                    BlockInput(FALSE);
                    cout << "\nAre you sure to confirm order?\n";
                    cout << "Press Y=Yes or N=No to confirm : ";        // ถามซ้ำอีกครั้งว่าต้องการยืนยันจริงหรือไม่
                    cin >> warnConfirm;
                    BlockInput(TRUE);
                    warnConfirm = toupper(warnConfirm);
                    
                    if (warnConfirm=='Y')       // หากกด Y จะยืนยันและอัพเดตจำนวนสินค้าในคลัง ลดลงตามจำนวนที่ซื้อ
                    {    
                        if (amountItem>0)
                        {   
                            for (int i=0; i<3; i++)
                            {
                                for (int k=0; k<4; k++)
                                    stockDefault[i][k] = stock[i][k];
                            }

                            success = true;
                            confirm = true;
                            break;
                        }
                    }
                    else if (warnConfirm=='N')       // หากกด N จะไม่ยืนยัน และกลับไปเลือกสินค้าต่อ
                    {    
                        categoryID = 9;
                    }
                    else
                    {
                        cout << "\nConfirm fail.";
                        BlockInput(TRUE);
                        Sleep(2500);
                    }
                }
                else
                {
                    categoryID = 9;
                    cout << "\nCart is empty, please choose item.\n";       // หากเรากดยืนยันคำสั่งซื้อแค่ตะกร้าว่างเปล่าจะแสดงข้อความแจ้งเตือน
                    Sleep(3000);
                    BlockInput(FALSE);
                }
                
            }
            else if (category=='X')         // ถ้ากด X จะเป็นการยกเลิกคำสั่งซื้อ
            {
                char warnConfirm;

                BlockInput(FALSE);
                cout << "\nAre you sure to cancel order?\n";            // ถามซ้ำอีกครั้งว่าต้องการยกเลิกจริงหรือไม่
                cout << "Press Y=Yes or N=No to cancel : ";
                cin >> warnConfirm;
                BlockInput(TRUE);
                warnConfirm = toupper(warnConfirm);
                
                if (warnConfirm=='Y')           // หากกด Y จะยกเลิกและจำนวนสินค้าในคลังจะคืนกลับค่าเดิม
                { 
                    for(int i=0; i<3; i++)
                    {
                        for(int k=0; k<4; k++)
                            stock[i][k] = stockDefault[i][k];
                    }

                    success = true;
                    confirm = false;
                    break;
                }
                else if (warnConfirm=='N')      // หากกด N จะไม่ยกเลิก
                {    
                    categoryID = 9;
                }
                else
                {
                    cout << "\nCancel fail.";
                    BlockInput(TRUE);
                    Sleep(2500);
                }
            }
            else if (category=='T')         // ถ้ากด T จะเข้าไปที่ตะกร้า ซึ่งแสดงสินค้า จำนวน และราคาทั้งหมดของสินค้าที่่เลือก
            {
                Cart(amountItem, OrderID, cartProduct, cartAmount, cartPrice);
                BlockInput(FALSE);
            }
            else
            {
                categoryID = 9;
                cout << "\nInvalid category, try again.";       // ถ้า ID ไม่ถูกต้องจะให้ป้อนใหม่
                BlockInput(TRUE);
                Sleep(2500);
                BlockInput(FALSE);
            }
        } while (categoryID==9);


        if (category!='T' && categoryID!=9 && !success)
        {
            do
            {
                system("cls");
                Stock(pricePPU, stock, product);                // ถ้าเลือกหมวดหมู่สินค้าเสร็จแล้วก็จะให้ป้อน ID สินค้าที่แสดงเป็นตัวเลข
                cout << "\n(Y=Confirm, X=Cancel, T=Cart)\n";
                cout << "Choose Category ID : " << category << endl;
                BlockInput(FALSE);
                cout << "Choose Product ID : ";
                cin >> item;
                BlockInput(TRUE);

                if (item<1 || item>4)
                {
                    cout << "\nInvalid product, try again.";        // ถ้า ID ไม่ถูกต้องจะให้ป้อนใหม่
                    Sleep(2500);
                }
            } while (item<1 || item>4);
            item -= 1;

            do
            {
                system("cls");
                Stock(pricePPU, stock, product);                    // ถ้าเลือกหมวดหมู่สินค้าเสร็จแล้วก็จะให้ป้อนจำนวนสินค้าที่ต้องการ
                cout << "\n(Y=Confirm, X=Cancel, T=Cart)\n";
                cout << "Choose Category ID : " << category << endl;
                cout << "Choose Product ID : " << item+1 << endl;
                cout << "Enter Amount : ";
                BlockInput(FALSE);
                cin >> amount;
                BlockInput(TRUE);

                if (amount>0)
                {
                    if (amount>stock[categoryID][item])             // ถ้าป้อนจำนวนสินค้ามากกว่าที่มีในสต็อค จำนวนสินที่ป้อนจะเท่ากับจำนวนสินค้าที่เหลือในสต็อค หรือเท่ากับ 0
                    {
                        amount = stock[categoryID][item];
                        stock[categoryID][item] = 0;
                    }
                    else
                        stock[categoryID][item] -= amount;          // ถ้าป้อนจำนวนสินค้าน้อยกว่าหรือเท่ากับจำนวนสินค้าที่มีในสต็อค สต็อคก็จะถูกลบออกตามจำนวนที่ป้อน เพื่อแสดงจำนวนสินค้าในสต็อคแบบเรียลไทม์


                    bool cartDuplicate=false;
                    for (int i=0; i<amountItem; i++)
                    {
                        if (product[categoryID][item]==cartProduct[i])          // ถ้าสินค้าในสต็อคซ้ำกันจะแสดงผลค่าอันเดียว และเพิ่มจำนวนแทน
                        {
                            cartAmount[i] += amount;
                            cartDuplicate = true;
                            break;
                        }
                    }
                    if (!cartDuplicate)
                    {
                        cartProduct[amountItem] = product[categoryID][item];
                        cartPrice[amountItem] = pricePPU[categoryID][item];     // ถ้าไม่ซ้ำกันจะเพิ่มสินค้าเข้าให้ตะกร้าเลย
                        cartAmount[amountItem] = amount;
                        amountItem++;
                    }
                }
                else
                {
                    cout << "\nIncorrect quantity, try again.";     // ถ้าจำนวนสินค้าน้อยกว่า 0
                    Sleep(2500);
                }
            } while (amount<0);
            
            item = 0;
            Sleep(500);
        }
    }
    
    if (success)
    {   
        float totalOrder=0, total;

        // เมื่อเลือกสินค้าเสร็จแล้วก็จะสรุปรายการคำสั่งซื้อว่ายืนยันหรือยกเลิก โดยแสดงชื่อสินค้า จำนวน ราคา ภาษีมูลค่าเพิ่ม และราคาสุทธ
        if (confirm)
        {   // ยืนยัน
            system("cls");
            cout << "Sale Order #" << OrderID << " | "<< ID << endl << endl;
            cout << setfill('=') << setw(39) << " " << endl;
            cout << "No.  Product" << setfill(' ') << setw(17) << "P/U" << setfill(' ') << setw(9) << "Qty." << endl;
            cout << setfill('-') << setw(39) << " " << endl;
            
            for (int i=0; i<amountItem; i++)
            {
                cout << right << setw(2) << setfill(' ') << i+1 << "   " << left << setw(12) << setfill(' ') << cartProduct[i];
                cout << setfill(' ') << setw(12) << right << fixed << setprecision(2) << cartPrice[i] << right << setprecision(0) << setw(8) << cartAmount[i] << setfill(' ') << endl;
                
                totalOrder += cartPrice[i]*cartAmount[i];
            }  
            total = totalOrder+(totalOrder*(vat/100.0));

            cout << endl << setfill(' ') << setw(26) << right << fixed << setprecision(2) << "Price : " << right << setw(12) << totalOrder << endl;
            cout << setfill(' ') << setw(21) << right << setprecision(0) << "Vat " << vat << "% : " << right << setprecision(2) << setw(12) << totalOrder*(vat/100.0) << endl;
            cout << setfill(' ') << setw(26) << right << "Total : " << right << setw(13-(to_string(total).length()-3)) << "$" << total << setprecision(0) << endl;
            cout << setfill('=') << setw(39) << " " << endl;
            cout << "\nOrder Success.\n\n";
            
            // สร้างไฟล์และเขียนข้อมูลการสั่งซื้อของลูกค้าลงในไฟล์ที่เป็นชื่อรหัสูกค้า
            const string CustomerFile = ID+".dat";
            ofstream OutCustomer(Path+CustomerPath+CustomerFile.c_str(), ios_base::out | ios_base::app);
            if (OutCustomer.is_open())
            {
                ifstream InCustomer(Path+CustomerPath+CustomerFile.c_str(), ios_base::in);
                if (InCustomer.is_open())
                {
                    string line;
                    getline(InCustomer, line);
                    if (line.empty())
                    {
                        int lineLenght;
                        if (name.length()>email.length())
                            lineLenght = name.length();
                        else
                            lineLenght = email.length();
                        string lineD(8+((lineLenght>11)?lineLenght:11), '=');

                        OutCustomer << lineD << endl;
                        OutCustomer << left << setw(10) << "Custommer ID : "+ID << endl;
                        OutCustomer << "Name  : " << name << endl;
                        OutCustomer << "Email : " << email << endl;
                        OutCustomer << lineD << endl << endl;
                        OutCustomer << setw(14) << "Product" << right << setw(8) << "P/U" << right << setw(10) << "Qty."<< endl << endl;
                    }

                    while (getline(InCustomer, line))
                    {
                        if (line.empty())
                            break;
                    }
                    
                    for (int i=0; i<amountItem; i++)
                        OutCustomer << left << setw(14) << cartProduct[i] << right << setw(8) << fixed << setprecision(2) << cartPrice[i] << setprecision(0) << right << setw(10) << cartAmount[i] << endl;
                }
                InCustomer.close();
            }
            else
                cout << CustomerFile << " : not accessible\nUnable to access customer data files." << endl;
            OutCustomer.close();

            // สร้างไฟล์และเขียนวันที่ และยอดการสั่งซื้อของวันที่ซื้อสินค้าลงในไฟล์เก็บข้อมูลการซื้อแต่ละวัน
            ofstream OutLog(Path+DailyLog.c_str(), ios_base::out | ios_base::app);
            if (OutLog.is_open())
            {
                ifstream InLog(Path+DailyLog.c_str(), ios_base::in);
                if (InLog.is_open())
                {
                    string line;
                    getline(InLog, line);
                    if (line.empty())
                        OutLog << "Date" << right << setw(28) << "Total" << endl << endl;
                    OutLog << date << right << setw(24) << fixed << setprecision(2) << total << endl;
                }
                InLog.close();
            }
            else
                cout << DailyLog << " : not accessible\nUnable to access the order record file." << endl;
            OutLog.close();
            
            // สร้างไฟล์และเขียนชื่อสินค้า และจำนวนในไฟล์ที่เป็นชื่อตามวันที่ที่สั่งซื้อของแต่ละวัน
            date[2]='_', date[5]='_';
            const string DailyFile = date+".dat";
            ofstream OutDaily(Path+DailyPath+DailyFile.c_str(), ios_base::out | ios_base::app);
            if (OutDaily.is_open())
            {
                ifstream InDaily(Path+DailyPath+DailyFile.c_str(), ios_base::in);
                if (InDaily.is_open())
                {
                    string line;
                    getline(InDaily, line);
                    if (line.empty())
                    {
                        OutDaily << left << setw(14) << "Product" << right << setw(10) << "Qty." << endl << endl;
                    }
                    for (int i=0; i<amountItem; i++)
                        OutDaily << left << setw(14) << cartProduct[i] << right << setw(9) << cartAmount[i] << endl;      
                }
                OutDaily.close();
            }
            else
                cout << DailyFile << " : not accessible\nUnable to access daily record file." << endl;
            OutDaily.close();

            Update = false;
        }
        else
        {   // ยกเลิก
            system("cls");
            cout << "Sale Order #" << OrderID << endl << endl;
            cout << setfill('*') << setw(39) << " " << endl;
            cout << "No.  Product" << setfill(' ') << setw(17) << "P/U" << setfill(' ') << setw(9) << "Qty." << endl;
            cout << setfill('-') << setw(39) << " " << endl;

            for(int i=0; i<amountItem; i++)
            {
                cartAmount[i]=0;
                cout << right << setw(2) << setfill(' ') << i+1 << "   " << left << setw(12) << setfill(' ') << cartProduct[i];
                cout << setfill(' ') << setw(12) << right << fixed << setprecision(2) << cartPrice[i] << right << setprecision(0) << setw(8) << cartAmount[i] << setfill(' ') << endl;
                
                totalOrder += cartPrice[i]*cartAmount[i];
            }  
            total = totalOrder+(totalOrder*(vat/100.0));

            cout << endl << setfill(' ') << setw(29) << right << fixed << setprecision(2) << "Price : " << right << setw(11) << totalOrder << endl;
            cout << setfill(' ') << setw(24) << right << setprecision(0) << "Vat " << vat << "% : " << right << setprecision(2) << setw(11) << totalOrder*(vat/100.0) << endl;
            cout << setfill(' ') << setw(29) << right << "Total : " << right << setw(12-(to_string(total).length()-3)) << "$" << total << setprecision(0) << endl;
            cout << setfill('*') << setw(39) << " " << endl;
            cout << "\nOrder Cancel.\n\n";

            CustomerID--;
        }

        // อัพเดตสต็อค
        ofstream OutStock(Path+StockFile.c_str(), ios_base::out | ios_base::trunc);
        if (OutStock.is_open())
        {
            OutStock << left << setw(15) << "Product" << "  " << "  Price" << "\t\t" << "Stock\n\n";
            for (int i=0; i<3; i++)
            {
                for (int k=0; k<4; k++)
                {
                    OutStock << left << setw(15) << product[i][k] << "  " << right << setw(7) << fixed << setprecision(2) << pricePPU[i][k] << "\t\t" << setw(5) << setprecision(0) << stock[i][k] << endl;
                }
                if(i<2)
                    OutStock << endl;
            }
        }
        else
        {
            cout << StockFile << " : not accessible\nUnable to access product information in the warehouse." << endl;
        }
        OutStock.close();
    }

    //อัพเดตรหัสลูุกค้า และจำนวนออเดอร์
    CustomerID = LastID;
    ofstream OutID(Path+ID_File.c_str(), ios_base::out | ios_base::app);
    if (OutID.is_open())
        OutID << right << setw(5) << OrderID << "\t\t" << setw(7) << CustomerID << endl;
    else
        cout << ID_File << " : not accessible\nUnable to access ID log file." << endl;
    OutID.close();


    BlockInput(FALSE);
    system("pause");
    system("cls");
}


//#############################################################################


void Cart(int amountItem, int OrderID, string cartProduct[24], int cartAmount[24], float cartPrice[24])             // ตะกร้าสินค้า
{
    float totalCart=0;

    system("cls");
    cout << "Products in the cart\n\n";
    cout << setfill('-') << setw(39) << " " << endl;
    cout << "No.  Product" << setfill(' ') << setw(17) << "P/U" << setfill(' ') << setw(9) <<"Qty." << endl;
    cout << setfill('-') << setw(39) << " " << endl;
    
    if (amountItem>0)
    {
        for(int i=0; i<amountItem; i++)
        {
            cout << right << setw(2) << setfill(' ') << i+1 << "   " << left << setw(12) << setfill(' ') << cartProduct[i];
            cout << setfill(' ') << setw(12) << right << fixed << setprecision(2) << cartPrice[i] << setfill(' ') << right << setprecision(0) << setw(9) << cartAmount[i] << setfill(' ') << endl;
            
            totalCart += cartPrice[i]*cartAmount[i];
        }
    }
    else
        cout << "Cart is empty\n";

    cout << endl << setfill(' ') << setw(29) << right << "Price : " << right << setprecision(2) << setw(10-(to_string(totalCart).length()-3)) << "$" << totalCart << setprecision(0) << endl;
    cout << setfill('-') << setw(39) << " " << endl << endl;
    
    
    BlockInput(FALSE);
    system("pause");
}


//#############################################################################
//                              CHECK & UPDATE
//#############################################################################


void CheckStock(int stockDefault[3][4], int stock[3][4], string product[3][4], float pricePPU[3][4])        // เช็คสต็อค
{
    int error=0, soldout=0;
    int productStock;
    float productPrice;
    string productName;
    string line;


    ofstream OutStock(Path+StockFile.c_str(), ios_base::out | ios_base::app);           // สร้างไฟล์เก็บสินค้าในคลัง
    if (OutStock.is_open())
    {
        ifstream InStock(Path+StockFile.c_str(), ios_base::in);
        if (InStock.is_open())
        {            
            string line;

            getline(InStock, line);
            if (line.empty())           // ถ้าไฟล์ว่างเปล่าจะทำการสุ่มจำนวนสินค้าแต่ละอัน และเขียนลงไปในไฟล์
            {
                srand(time(NULL));
                for(int i=0; i<3; i++)
                {
                    for(int k=0; k<4; k++)
                    {
                        stockDefault[i][k] = 75+rand()%(125-75+1);
                        stock[i][k] = stockDefault[i][k];
                    }
                }
                
                OutStock << left << setw(14) << "Product" << right << setw(8) << "Price" << setw(10) << "Stock\n\n";
                for (int i=0; i<3; i++)
                {
                    for (int k=0; k<4; k++)
                    {
                        OutStock << left << setw(14) << ProductAdd[i][k] << right << setw(8) << fixed << setprecision(2) << PriceAdd[i][k] << setw(10) << setprecision(0) << stock[i][k] << endl;
                    }
                    if(i<2)
                        OutStock << endl;
                }
            }
            else
            {
                while (InStock >> productName >> productPrice >> productStock)      // เช็คสต็อคว่าจำนวนสินค้าหมดหรือมี Error หรือไม่
                {
                    if (productStock > 125 || productStock < 0)
                        error++;
                    else if (productStock == 0)
                        soldout++;
                }
            }
        }
        InStock.close();
    }
    else
    {
        cout << StockFile << " : not accessible\nUnable to access product information in the warehouse." << endl;
    }
    OutStock.close();


    if (error>=3 || soldout>=4)         // หากจำนวนสินค้าหมดหรือมี Error จะสุ่มและเขียนขึ้นมาใหม่
    {
        string sysOut = "cd "+Path+" && del \""+StockFile+"\" && cd..";
        const char *cmd = sysOut.c_str();
        system(cmd);
        CheckStock(stockDefault, stock, product, pricePPU);
        system("cls");
    }


    ifstream InStock(Path+StockFile.c_str(), ios_base::in);         // เปิดไฟล์สต็อคสินค้าเพื่อเก็บข้อมูลไปใช้งาน
    if (InStock.is_open())
    {
        int i = -1, k = 0;

        getline(InStock, line);
        while (getline(InStock, line))
        {
            if (line.empty())
                i++, k = 0;

            istringstream productList(line);
            while (productList >> productName >> productPrice >> productStock)
            {
                product[i][k] = productName;
                pricePPU[i][k] = productPrice;
                stock[i][k] = productStock;
                k++;
            }
        }
    }
    InStock.close();
}


//#############################################################################


void UpdateID(int &OrderID, int &CustomerID)            // อัพเดตรหัสลูกค้า และจำนวนออเดอร์
{
    ofstream OutID(Path+ID_File.c_str(), ios_base::out | ios_base::app);
    if (OutID.is_open())
    {
        ifstream InID(Path+ID_File.c_str(), ios_base::in);
        if (InID.is_open())
        {
            string line;
            getline(InID, line);
            if (line.empty())           // หากไฟล์ว่างเปล่าจะเขียนค่าเริ่มต้นให้คือ 0
            {
                OutID << "OrderID" << "\t\t" << "CustomerID" << endl << endl;
                OutID << right << setw(5) << 0 << "\t\t" << setw(7) << 0 << endl;
                OrderID = 1;
                CustomerID = 0;
            }
            else
            {
                int order_id, customer_id;      // อัพเดตรหัสลูกค้า และจำนวนออเดอร์ทุกครั้งเมื่อเปิดโปรแกรมหรือซื้อสินค้าเสร็จ

                while (!InID.eof())
                {
                    InID >> order_id >> customer_id;
                    OrderID = order_id+1;
                    CustomerID = customer_id+1;
                }
            }
        }
        InID.close();
    }
    else
        cout << ID_File << " : not accessible\nUnable to access ID log file." << endl;
    OutID.close();
}


//#############################################################################
//                                LOGIN
//#############################################################################


bool MainLogin()            // หน้าหลักให้เลือกเข้าสู่ระบบ หรือสมัครบัญชี
{
    bool resultReturn;
    char LoginMenu;


    ofstream OutAccount(Path+AccountFile.c_str(), ios_base::out | ios_base::app);       // สร้างไฟล์เพื่อเก็บบัญชีผู้ใช้งาน หากไฟล์ว่างเปล่าจะกำหนดบัญชีผู้ใช้งานให้ คือ Username:admin และ Password:root123
    if (OutAccount.is_open())
    {
        ifstream InAccount(Path+AccountFile.c_str(), ios_base::in);
        if (InAccount.is_open())
        {
            string line;

            getline(InAccount, line);
            if (line.empty())
            {
                OutAccount << left << setw(20) << "Username" << "  " << "Password\n\n";
                OutAccount << left << setw(20) << "admin" << "  " << "root123\n";
            }
        }
        InAccount.close();
    }
    else
        cout << AccountFile << " : not accessible\nUnable to access user account database." << endl;
    OutAccount.close();

    do
    {
        system("cls");
        cout << setfill('=') << setw(25) << "\n\n";
        cout << " 1. Login\n\n 2. Register\n\n 3. Exit Program\n\n";
        cout << setfill('=') << setw(25) << "\n\n";
        cout << "Please choose menu : ";
        cin >> LoginMenu;
        BlockInput(TRUE);

        switch (LoginMenu)
        {
            case '1':
                system("cls");
                resultReturn = Login();
                break;

            case '2':
                system("cls");
                Register();
                break;

            case '3':
                resultReturn = false;
                break;

            default:
                cout << "\nInvalid menu, try again.\n";
                Sleep(2500);
                system("cls");
        }
        if (resultReturn)
            break;
    } while (LoginMenu!='3');
    
    return resultReturn;
}


//#############################################################################


bool Login()            // เมนูล็อคอิน
{   
    bool resultReturn, success=false, foundUser=false;
    int count=1;
    int tryLogin=3;         // ตั้งค่าจำนวนครั้งที่เข้าสู่ระบบได้
    string userIn, passIn;


    cout << "=========== Login ===========\n"<< endl;
    while (!success && count<=3)
    {
        cout << "Username : ";
        BlockInput(FALSE);
        cin >> userIn;          // ป้อนชื่อผู้ใช้งาน
        BlockInput(TRUE);

        ifstream InAccount(Path+AccountFile.c_str(), ios_base::in);     // เปิดไฟล์เก็บข้อมูลผู้ใช้งานมาอ่านว่าชื่อผู้ใช้งานตรงกับบัญชีผู้ใช้งานที่มีในฐานข้อมูลหรือไม่
        if (InAccount.is_open())
        {
            string user, pass;

            while (!InAccount.eof() || count>tryLogin || !success)
            {   
                InAccount >> user >> pass;
                if (userIn==user)
                {
                    count = 1;
                    foundUser = true;
                    cout << "Password : ";
                    BlockInput(FALSE);
                    cin >> passIn;
                    BlockInput(TRUE);

                    if (passIn==pass)
                    {
                        success = true;
                        break;
                    }

                    if (!success)
                    {
                        count++;
                        cout << "\nIncorrect Password, try agian\n" << endl;
                        BlockInput(TRUE);
                        Sleep(2500);
                        BlockInput(FALSE);
                        system("cls");
                        do
                        {
                            cout << "=========== Login ===========\n"<< endl;       // ถ้าชื่อผู้ใช้ตรงกับบัญชีผู้ใช้ในฐานข้อมูลให้ป้อนรหัสผ่าน
                            cout << "Username : " << userIn << endl;
                            cout << "Password : ";
                            BlockInput(FALSE);
                            cin >> passIn;
                            BlockInput(TRUE);

                            if (passIn==pass)
                            {
                                success = true;
                                break;
                            }
                            
                            if (!success)
                            {
                                count++;

                                if (count>tryLogin)
                                    cout << "\nIncorrect Password\n";           // ถ้ารหัสผ่านไม่ถูกต้องจะขึ้นแจ้งเตือน
                                else
                                {
                                    cout << "\nIncorrect Password, try agian\n" << endl;
                                    BlockInput(TRUE);
                                    Sleep(2500);
                                    BlockInput(FALSE);
                                    system("cls");
                                }
                            }
                            else
                                break;

                        } while (!success && count<=tryLogin);

                        if (count>tryLogin)
                            break;
                    }
                    else
                        break;
                }
            }
            InAccount.close();

            if (!foundUser)
            {
                count++;

                if (count>tryLogin)
                    cout << "\nInvalid Username\n";             // ถ้าชื่อผู้ใช้ไม่ถูกต้องจะขึ้นแจ้งเตือน
                else
                {
                    cout << "\nInvalid Username, try again\n" << endl;
                    BlockInput(TRUE);
                    Sleep(2500);
                    BlockInput(FALSE);
                    system("cls");
                    cout << "=========== Login ===========\n"<< endl;
                }
            }
        }
        else
            cout << AccountFile << " : not accessible\nUnable to access user account database." << endl;
    }


    if (success)
    {
        cout << "\n" << setfill('=') << setw(31) << " \n";              // ถ้าชื่อผู้ใช้และรหัสผ่านถูกต้องจะขึ้นแจ้งเตือน
        BlockInput(TRUE);
        Sleep(500);
        system("color a");
        Sleep(1000);
        cout << "\nSystem :\nLogin Success, Welcome!\n" << setfill('=') << setw(31);
        Sleep(2500);
        system("cls");
        system("color f");
        resultReturn = true;
        BlockInput(FALSE);
    }
    else
    {
        cout << "\n" << setfill('=') << setw(31) << " \n";              // ถ้าพยายามเข้าสู่ระบบเกินจำนวนครั้งที่ตั้งไว้จะขึ้นแจ้งเดือน
        BlockInput(TRUE);
        Sleep(500);
        system("color c");
        Sleep(1000);
        cout << "\nWarning :\nYou have exceeded your login attempts.\n" << setfill('=') << setw(31);
        Sleep(2500);
        system("cls");
        resultReturn = false;
        BlockInput(FALSE);

        char warnNewAccount;
        do
        {
            system("color 6");
            cout << setfill('*') << setw(35) << " \n" << endl;              // ถ้าพยายามเข้าสู่ระบบเกินจำนวนครั้งที่ตั้งไว้จะมีเมนูให้เลือก
            cout << "Help :\nDo you want to create an account?\n\n\n";
            cout << "A) Create Account\nB) Back\n\n";
            cout << setfill('*') << setw(35) << " \n" << endl;
            cout << "Choose Menu : ";
            BlockInput(TRUE);
            cin >> warnNewAccount;
            BlockInput(FALSE);
            warnNewAccount = toupper(warnNewAccount);

            if (warnNewAccount=='A')            // ถ้ากด A จะสมัครบัญชีใหม่
            {
                system("color f");
                resultReturn = Register();
                break;
            }
            else if (warnNewAccount=='B')       // ถ้ากด B จะกลับหน้าหลัก
            {
                system("color f");
                system("cls");
                break;
            }
            else
            {
                cout << "\nInvalid menu, please try again.";
                BlockInput(TRUE);
                Sleep(2500);
                BlockInput(FALSE);
                system("cls");
            }
        } while (warnNewAccount!='B');
        
        if (warnNewAccount=='A')
            Login();
        else
            system("cls");
    }

    return resultReturn;
}


//#############################################################################


bool Register()             // สมัครบัญชีผู้ใช้
{
    int tryRegister=3;
    int count=0;
    string checkPass, newPass, newUser;
    bool resultReturn, duplicate=false ;


    do
    {
        system("cls");
        cout << "=========== Register ===========\n"<< endl;
        cout << "New Username : ";
        BlockInput(FALSE);
        cin >> newUser;             // ป้อนชื่อผู้ใช้ใหม่

        duplicate=false;
        string user, pass;

        ifstream InAccount(Path+AccountFile.c_str(), ios_base::in);
        if (InAccount.is_open())
        {
            while (!InAccount.eof())
            {   
                InAccount >> user >> pass;
                if (newUser==user)              // หากชื่อผู้ใช้ใหม่ตรงกับชื่อผู่ใช้ที่มีอยู่ในฐานข้อมูลแล้วจะไม่สามารถใช้ได้ และให้ตั้งชื่อใหม่
                {
                    cout << "\nThis username cannot be used.\n";
                    Sleep(1500);
                    duplicate = true;
                    break;
                }
            }
            InAccount.close();
        }
        else
            cout << AccountFile << " : not accessible\nUnable to access user account database." << endl;
    } while (duplicate==true);
    
    

    BlockInput(TRUE);
    cout << "New Password : ";          // ตั้งรหัสผ่าน
    BlockInput(FALSE);
    cin >> newPass;
    BlockInput(TRUE);
    cout << "Confirm Password : ";      // ใส่รหัสผ่านอีกครั้งเพื่อตรวจสอบ
    BlockInput(FALSE);
    cin >> checkPass;
    BlockInput(TRUE);
    count++;


    if (checkPass!=newPass)
    {   
        cout << "\nPassword is don't match, try again.";        // ถ้ารหัสผ่านไม่ตรงกันจะให้ป้อนรหัสอีกครั้ง
        BlockInput(TRUE);
        Sleep(2500);
        BlockInput(FALSE);
        system("cls");

        while (checkPass!=newPass && count<tryRegister)
        {
            system("cls");
            cout << "=========== Register ===========\n"<< endl;
            cout << "New Username : " << newUser << endl;
            cout << "New Password : " << newPass << endl;
            cout << "Confirm Password : ";
            BlockInput(FALSE);
            cin >> checkPass;
            BlockInput(TRUE);
            count++;

            if (count==tryRegister)
            {
                cout << "\nPassword is don't match\n\n";
                cout << setfill('=') << setw(33) << " " << endl;
            }

            if (checkPass!=newPass && count<tryRegister)
            {
                cout << "\nPassword is don't match, try again.\n";
            }

            BlockInput(TRUE);
            Sleep(2500);
            BlockInput(FALSE);
            system("cls");
        }  
    }

    if (count==tryRegister)                 // ถ้าป้อนรหัสผ่านไม่ตรงกันเกินจำนวนครั้งที่ตั้งไว้ การสร้างบัญชีจะไม่สำเร็จ
    {
        char warnRegister;
        
        do
        {
            system("color 6");
            cout << setfill('*') << setw(35) << " \n" << endl;      // มีเมนูให้เลือก
            cout << "Create account faill.\n\n";
            cout << "B) Back to Home\nQ) Exit\n\n";
            cout << setfill('*') << setw(35) << " \n" << endl;
            cout << "Choose menu : ";
            BlockInput(TRUE);
            cin >> warnRegister;
            BlockInput(FALSE);
            warnRegister = toupper(warnRegister);

            if (warnRegister=='B')          // ถ้ากด B จะกลับเมนูหลัก
            {
                system("cls");
                MainLogin();
            }
            else if (warnRegister=='Q')     // ถ้ากด Q จะออกจากโปรแกรม
            {
                resultReturn = false;
                break;
            }
            else
            {
                cout << "\n\nInvalid menu, try again.";
                system("cls");
                cout << setfill('=') << setw(33) << " " << endl;
            }
        } while ((warnRegister!='B')||(warnRegister!='Q'));
    }
    else
    {
        ofstream OutAccount(Path+AccountFile.c_str(), ios_base::out | ios_base::app);       // ถ้าสร้างบัญชีผู้ใช้ใหม่สำเร็จจะบันทึกชื่อผู้ใช้และรหัสผ่านลงในไฟล์เก็บข้อมูลบัญชีผู้ใช้
        if (OutAccount.is_open())
            OutAccount << left << setw(20) << newUser << "  " << newPass << endl;
        else
            cout << AccountFile << " : not accessible\nUnable to access user account database." << endl;
        OutAccount.close();

        cout << "\n" << setfill('=') << setw(33) << " " << endl;
        cout << "\nCreate account success.";
        BlockInput(TRUE);
        Sleep(3000);
        BlockInput(FALSE);
        system("cls");
        resultReturn = true;
    }

    return resultReturn;
}


//#############################################################################
//                             DISPLAY CHECK
//#############################################################################


void NoData()           // ข้อมูลว่างเปล่า
{
    cout << setfill('*') << setw(39) << " " << endl;
    cout << " No customer order information found.\n";
    cout << setfill('*') << setw(39) << " " << endl << endl;
    system("pause");
}


//#############################################################################


void NotFound(string type)      // ไม่พบข้อมูลที่ค้นหา
{
    cout << setfill('*') << setw(24) << " " << endl;
    cout << " This " << type << " was not found.\n";
    cout << setfill('*') << setw(24) << " " << endl << endl;
}


//#############################################################################


bool DateFormat_Check(string checkDate)         // เช็ครูปแบบวันที่
{
    bool result = false;
    string dd, mm, yy;
    int yearNow = 2023;      // ปี สามารถตั้งได่ (2010-2023)

    if (checkDate.length() == 8)
    {

        dd += checkDate[0];
        dd += checkDate[1];
        mm += checkDate[3];
        mm += checkDate[4];
        yy += checkDate[6];
        yy += checkDate[7];
        int day = stoi(dd), month = stoi(mm), year = stoi(yy);
        

        int maxDay, monthNow=12;
        if (year==(2000-yearNow))
            monthNow=11;


        if (month==2)
        {
            int y = 2000 + year;

            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                maxDay = 29;
            else
                maxDay = 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            maxDay = 30;
        else
            maxDay = 31;
        

        if ((checkDate.length()!=8) || (day<1 || day>maxDay) || (month<1 || month>monthNow) || (year<10 || year>23) || (checkDate[2]!='/') || (checkDate[5]!='/'))
        {
            cout << "\nInvalid date format, try again.";
            BlockInput(TRUE);
            Sleep(2500);
            BlockInput(FALSE);
            system("cls");
        }
        else
            result = true;
    }

    if (checkDate.length() != 8)
    {
        cout << "\nInvalid date format, try again.";
        Sleep(2000);
    }

    return result;
}


//#############################################################################


bool NameFormat_Check(string Name, string type)         // ตรวจสอบรูปแบบชื่อและนามสกุล
{
    bool result = false;
    int upper=0, lower=0,number=0, special=0;
    
    for (int i=0; i<Name.length(); i++)
    {
        if (Name[i] >= 'A' && Name[i] <= 'Z')
            upper++;
        else if (Name[i] >= 'a' && Name[i] <= 'z')
            lower++;
        else if (Name[i]>= '0' && Name[i]<= '9')
            number++;
        else
            special++;
    }

    if ((Name[0] >= 'A' && Name[0] <= 'Z')&&(upper==1 && lower!=0 && number==0 && special==0))
        result = true;
    else
    {
        cout << "\nInvalid " << type << " format, try again.";
        BlockInput(TRUE);
        Sleep(2500);
        BlockInput(FALSE);
        system("cls");
    }


    return result;
}


//#############################################################################


bool EmailFormat_Check(string emailCheck)           // ตรวจสอบรูปแบบอีเมล
{
    bool result=false, charFirst=false, lastChar=false;
    int At=0, Dot=0, lastAt, lastDot, BeforeAt, special=0;
    
    charFirst = (emailCheck[0] >= 'a' && emailCheck[0] <= 'z');
    
    for (int i=0; i<emailCheck.length(); i++)
    {
        if (emailCheck[i]=='@')
        {
            At++;
            lastAt = i+1;
            BeforeAt = i;
        }
    }

    for (int i=lastAt; i<emailCheck.length(); i++)
    {
        if ((emailCheck[i]=='.') && i>lastAt)
        {
            Dot++;
            lastDot = i;
        }
    }

    for (int i=lastDot; i<emailCheck.length(); i++)
    {
        lastChar = (emailCheck[i] >= 'a' && emailCheck[i] <= 'z');
    }

    for (int i=0; i<BeforeAt; i++)
    {
        if ((!isalpha(emailCheck[i]) && !isdigit(emailCheck[i]) && emailCheck[i]!='.'))
            special++;
    }

    if ((charFirst=true) && (lastChar=true) && special==0 && At==1 && Dot>=1 && islower(emailCheck[emailCheck.length()-1]))
    {
        result = true;
    }
    else
    {
        cout << "\nInvalid email format, try again.";
        BlockInput(TRUE);
        Sleep(2500);
        BlockInput(FALSE);
        system("cls");
    }

    return result;
}