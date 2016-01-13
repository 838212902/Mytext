//
//  buyer.h
//  2.0
//
//  Created by 中软mini028 on 15/8/7.
//  Copyright (c) 2015年 中软mini028. All rights reserved.
//

#ifndef ____0__buyer__
#define ____0__buyer__

#include <stdio.h>

#endif /* defined(____0__buyer__) */
//
//  conmistor.h
//  天天外卖
//
//  Created by 中软mini029 on 15/8/7.
//  Copyright (c) 2015年 中软mini029. All rights reserved.
//

#ifndef ________conmistor__
#define ________conmistor__

#include <stdio.h>
#define LENTH 20

#endif /* defined(________conmistor__) */
struct Cook                       //厨师信息
{
    char cookname[LENTH];         //厨师姓名
    char cookjudge[LENTH];        //厨师评价
    char cookbeizhu[LENTH];       //厨师备注
    
    
};
struct Dish                       //菜肴信息
{
    char dishname[LENTH];         //菜肴名字
    int price;                    //菜肴价格
    int suoshengnumber;           //菜肴所剩数量
    char dishjudge[LENTH];        //菜肴评价
    char dishmiaoshu[LENTH];      //菜肴描述
    char dishbeizhu[LENTH];       //菜肴备注
    struct Cook cook;
    
};
struct Buyman                     //买家信息
{
    int bnumber;             //买家编号
    char bname[LENTH];            //买家用户名
   	int bcode;             //买家用户密码
    int buymanmoney;              //买家钱包
    char buymanname[LENTH];       //买家姓名
    long  connect;                  //买家联系方式
    char buymanaddress[LENTH];    //买家地址
    int count;
};
struct storesort
{
    int sortnumber;//商店种类编号
    char sortname[20];//商店种类名称
};

struct Sellman                    //卖家信息
{
    char uname[20];//卖家用户名
    int ucode;//卖家用户密码
    int shopid;                   //店铺编号
    char shopname[LENTH];         //店铺名称
    struct storesort sort;        //店铺的类型
    char shopaddress[LENTH];      //店铺地址
    char shopjudge[LENTH];        //店铺评价
    int shopmoney;                //店铺钱包
    int ifzhuce;
};
struct Manager
{
    int number;//管理员编号
    char managername[20];//管理员名称
    int managercode;//管理员密码
};
struct Dingdan                    //订单信息
{
    int dingdanid;                //订单号
    int ifsongdao;                  //是否送达
    int shijiprice;               //实际交付的价钱
    int dshopid;                    //订单中商店编号
    char dbuyername[LENTH];         //订单中买家姓名
    int ifreceive;                  //是否收货
    int ifyizuo;                    //是否已做
    char ddishname[LENTH];          //订单中菜肴名称
    char djudge[LENTH];             //送餐评价
    int ifjiedan;
};

void buy(char *buyname);
void queryList();
void cancel();
void getDish();
void queryBuyerMoney(char buyname[]);
//void consult(char buyname[]);
char* changeMe(char buyname[]);
void queryByKind(char buyname[]);
void queryByPrice(struct Dish dishArr[LENTH][LENTH],char buyname[]);
void queryByCook(char buyname[]);
void queryByAddress(char buyname[]);
//void queryByDiscount();
void queryOld();
void queryNoRecive();
void queryDish(char shopkind[],char buyname[]);
int pay(int price,struct Buyman buyArr[],char buyname[]);
void buyer(char buyname[]);
void queryMList(int id);

void showselljiemian();           //卖家界面
void showdishgengxin();           //更新菜单
void showhistoryzhangdan();       //查询历史账单
void showchaxunpingjia();         //查询评价
int jiedan(int shopid);                    //接单
void genggaidingdanzhuangtai(int shopid);   //更改订单状态
void chaxundingdanzhuangtai(int shopid);     //查询订单状态
void chaxunshouzhiqingkuakng(int shopid);   //查询收支情况
void chaxundishpingjia(int shopid);         //查询菜品评价
void chaxuncookpingjia(int shopid);         //查询厨师评价
//void chaxunsongcanpingjia();      //查询送餐评价
int addcaipin(int shopid);                  //添加菜品
void genggaicaipinyuliang(int shopid);      //更改菜品余量
void genggaijiage(int shopid);              //更改价格
void genggaichushi(int shopid);             //更改厨师
void genggaishopleixing(int shopid);        //更改商店类型
void genggaiaddress(int shopid);            //更改地址
void chaxundishpingjia(int shopid);         //查询菜品评价
void chaxuncookpingjia(int shopid);         //查询厨师评价

void mainMenu();            //主菜单
void cseller();             //卖家系统
void sbuyer();
void manager();
void registorSeller();
void loginSeller();
void selectRegistor();
void modifySellerinfo();
void quit();
void managerLogin();
void modifymanagerinfo();
void managermenu();
void addseller();
void addbuyer();
void deleseller();
void delebuyer();
void active();
//void evaluate();
void registorbuyer();
void loginbuyer();
void selectcon();
void modifysellername(int i);
void modifysellercode(int i);
void modifystorename(int i);
void modifystorekind(int i);
void modifystoreaddress(int i);
void dish_arr( struct Dish arr[LENTH][LENTH]); //保存（写）
int loaddish_arr(char *fname, struct Dish arr[LENTH][LENTH]);    //加载（读）
void buyman_arr(struct Buyman * arr);//保存（写）
int loadbuyman_arr(char *fname, struct Buyman * arr);    //加载（读）
void sellman_arr(struct Sellman * arr); //保存（写）
int loadsellman_arr(char *fname, struct Sellman * arr);    //加载（读）
void dingdan_arr(struct Dingdan * arr); //保存（写）
int loaddingdan_arr(char *fname, struct Dingdan * arr);    //加载（读）
void manager_arr(struct Manager * arr); //保存（写）
int loadmanager_arr(char *fname, struct Manager * arr);    //加载（读）