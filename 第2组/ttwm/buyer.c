//
//  buyer.c
//  2.0
//
//  Created by 中软mini028 on 15/8/7.
//  Copyright (c) 2015年 中软mini028. All rights reserved.
//

#include "buyer.h"
#include "stdlib.h"
#include <string.h>
#define LENTH 20
struct Dish dish1[LENTH][LENTH]={
    [0][0]={"鱼香肉丝",20,10,"","","",{"jack","hao"}},
    [1][0]={"京酱肉丝",225,10,"","","",{"jack","hao"}}
    , [0][1]={"鱼香肉丝",20,10,"","","",{"john","hao"}}
    
};
struct Buyman buyArr[LENTH]={{1,"mary",1111,10000,"kehu",12,"",100},
    {2,"may",1111,10000,"kehu",12,"",1009},
    {3,"mry",1111,10000,"kehu",12,"",10}};
struct Sellman sellArr[LENTH]={{"clour",1111,1001,"123",{1,"快餐"},"add1"},{"aaaa",1111,1002,"456",{1,"快餐"},"add1"}};
struct Dingdan dingArr[LENTH];
struct storesort sortArr[20]={
    {1,"快餐"},
    {2,"烧烤"},
    {3,"火锅"},
    {4,"甜品类"},
    {5,"饮品类"}
};
struct Manager man[20]={
    {1,"manager",1234},
    {2,"a",1},
    {3,"b",2},
    {4,"c",3},
    {5,"d",4}
};
int dingdan=0;
void buyer(char buyname[])                                        //买家登陆后,
{
    
    
    do {
        printf("1.订餐\n");
        printf("2.查询订单情况\n");
        printf("3.取消订餐\n");
        printf("4.确认收货及评价\n");
        printf("5.查询余额\n");
        printf("6.修改个人信息\n");
        printf("请输入数字或输入0返回上一层:");
        int n;
        scanf("%d",&n);
        switch (n) {
            case 1:
                //订餐
                buy(buyname);
                break;
            case 2:
                //查询订单情况
                queryList();
                break;
            case 3:
                //取消订餐
                cancel(buyname);
                break;
            case 4:
                //确认收货及评价
                getDish();
                break;
            case 5:
                //查询余额
                queryBuyerMoney(buyname);
                break;
            case 6:
                //修改个人信息
                changeMe(buyname);
                break;
            default:
                break;
        }
        if (n==0) {//当选择0的时候，
            return ;//返回订单id
        }
    } while (1);
}
void buy(char buyname[])
{
    do {
        printf("1.根据商店类型查询\n2.根据价格查询\n3.根据厨师查询\n4.根据地址查询\n请输入数字或输入0返回上一层:");
        int n;
        scanf("%d",&n);
        switch (n) {
            case 1:
                //根据商店类型查询
                queryByKind(buyname);
                break;
            case 2:
                //根据价格查询
                queryByPrice(dish1,buyname);
                break;
            case 3:
                //根据厨师查询
                queryByCook(buyname);
                break;
            case 4:
                //根据地址查询
                queryByAddress(buyname);
                break;
            default:
                break;
        }
        if (n==0) {
            return ;
        }
        
    } while (1);
}
void queryList()
{
    do {
        printf("1.查询历史订单\n2.查询未收货订单\n");
        printf("请输入数字或输入0返回上一层:");
        int n;
        scanf("%d",&n);
        switch (n) {
            case 1:
                //查询历史订单
                queryOld();
                break;
            case 2:
                //查询未收货订单
                queryNoRecive();
                break;
            default:
                break;
        }
        if (n==0) {
            return;
        }
    }while (1);
}
void cancel(char buyname[])
{
    int id;
    printf("请输入订单号或输入0返回上一层");
    scanf("%d",&id);
    if (id==0)
    {
        return;
    }
    else
    {
        for (int i=0; i<LENTH; i++)             //订单循环
        {
            if (dingArr[i].dingdanid==id)
            {
                if (dingArr[i].ifyizuo==0)      //没有做的话可以取消
                {
                    dingArr[i].dingdanid=0;
                    dingdan_arr(dingArr);
                    printf("已取消订餐\n");
                    for (int j=0; j<LENTH;j++)  //改买家钱包
                    {
                        if (strcmp(buyArr[j].buymanname,buyname)==0)
                        {
                            buyArr[j].buymanmoney+=dingArr[i].shijiprice;
                            buyman_arr(buyArr);
                            printf("钱包余额为%d\n",buyArr[j].buymanmoney);
                        }
                    }return;
                }
                else if(dingArr[i].ifreceive==1)
                {
                    printf("买家已经收货!\n");
                    return;
                }else{
                    printf("餐厅已经开始做啦，请耐心等待～\n");
                    return;
                }
            }
        }
        return;
    }
}
void getDish()
{
    int id;
    int j;
    char p1[LENTH],p2[LENTH];
    for (int i=0; i<LENTH; i++)
    {
        printf("请输入订单号或输入0返回上一层");
        scanf("%d",&id);
        if (id==0)
        {
            return;
        }
        else
            if (dingArr[i].dingdanid==id&&dingArr[i].dingdanid!=0&&dingArr[i].ifjiedan==1,dingArr[i].ifyizuo==1)           //确认收货
            {
                dingArr[i].ifreceive=1;
                dingArr[i].ifsongdao=1;
                dingdan_arr(dingArr);
                printf("谢谢惠顾\n");
                for (j=0; j<LENTH; j++)
                {
                    if (dingArr[i].dshopid==sellArr[j].shopid)
                    {
                        sellArr[j].shopmoney+=dingArr[i].shijiprice;
                        break;
                    }
                }
                printf("请输入对本次点餐的评价:\n");
                printf("菜肴评价\n");
                scanf("%s",p1);
                char p11[LENTH]="@";
                strcat(p11,p1);
                strcpy(p1, p11);
                printf("厨师评价\n");
                scanf("%s",p2);
                char p22[LENTH]="@";
                strcat(p22,p2);
                strcpy(p2, p22);
                for (int k=0; k<LENTH; k++)
                {
                    if(strcmp(dish1[k][j].dishname,dingArr[i].ddishname)==0)
                        strcat(dish1[k][j].dishjudge,p1);
                    strcat(dish1[k][j].cook.cookjudge,p2);
                }dish_arr(dish1);
                return;
            }
            else
            {
                printf("无法收货\n");
                continue;
            }
    }
    
}
void queryBuyerMoney(char buyname[])
{
    
    for (int i=0; i<LENTH; i++) {
        printf("%s\t",buyArr[i].buymanname);
        if (strcmp(buyArr[i].buymanname,buyname)==0) {
            printf("钱包余额为%d\n",buyArr[i].buymanmoney);
            return;
        }
    }
}
/*void consult(char buyname[])
 {
 }*/
char* changeMe(char buyname[])
{
    char buymanname[LENTH];       //买家姓名
    long connect;                 //买家联系方式
    char buymanaddress[LENTH];    //买家地址
    for (int i=0; i<LENTH; i++) {
        if (strcmp(buyArr[i].buymanname,buyname)==0) {
            printf("请输入您的姓名\n");
            scanf("%s",buymanname);
            strcpy(buyArr[i].buymanname,buymanname);
            strcpy(buyname,buyArr[i].buymanname);
            printf("请输入您的联系方式\n");
            scanf("%ld",&connect);
            buyArr[i].connect=connect;
            printf("请输入您的地址\n");
            scanf("%s",buymanaddress);
            strcpy(buyArr[i].buymanaddress,buymanaddress);
            buyman_arr(buyArr);
            
            printf("%s,%ld,%s\n",buyArr[i].buymanname,buyArr[i].connect,buyArr[i].buymanaddress);
            return buyname;
        }
    }
    return buyname;
}
void queryByKind(char buyname[])
{
    do
    {
        printf("请选择商店类型:1.快餐2.烧烤3.火锅4.甜品5.饮品或输入0返回上一层\n");
        int n;
        char shopkind[LENTH];
        scanf("%d",&n);
        if (n==0)
        {
            return ;
        }
        else
        {
            switch (n)
            {
                case 1:
                {
                    strcpy(shopkind, "快餐");
                    queryDish(shopkind,buyname);
                    break;
                }
                case 2:
                {
                    strcpy(shopkind, "烧烤");
                    queryDish(shopkind,buyname);
                    break;
                }
                case 3:
                {
                    strcpy(shopkind, "火锅");
                    queryDish(shopkind,buyname);
                    break;
                }
                case 4:
                {
                    strcpy(shopkind, "甜品");
                    queryDish(shopkind,buyname);
                    break;
                }
                case 5:
                {
                    strcpy(shopkind, "饮品");
                    queryDish(shopkind,buyname);
                    break;
                }
                default:
                    break;
            }
            return ;
            
        }
        
    }while(1);
}
void queryByPrice(struct Dish dishArr[LENTH][LENTH],char buyname[])
{
    int n;
    int dn=0;                       //显示时菜肴的编号
    int m=0;                        //菜肴在显示时存的数组的下标
    int ddishid[LENTH];
    int dshopid[LENTH];
    char ddishname[LENTH][LENTH];
    int dChoose;                    //选择的菜肴编号
    int d=0;                        //找菜肴
    do{
        printf("请选择价位:1.0-100 2.100-200 3.200以上,或输入0返回上一层\n");
        scanf("%d",&n);
        if (n==0)
        {
            return ;
        }
        else
            switch (n)
        {
            case 1:
            {
                for (int i=0; i<LENTH; i++)
                {
                    for (int j=0; j<LENTH; j++)         //找菜肴
                    {
                        if (dish1[i][j].price>0&&dish1[i][j].price<=100)
                        {
                            printf("%d ",dn);
                            printf("%s,%d,%d\n",dish1[i][j].dishname,dish1[i][j].price,sellArr[j].shopid);
                            ddishid[m]=dn;
                            dshopid[m]=sellArr[j].shopid;
                            for (int a=0; a<LENTH; a++)
                            {
                                ddishname[m][a]=dish1[i][j].dishname[a];
                            }
                            m++;
                            dn++;
                        }
                    }
                }
                printf("请选择菜肴或输入123返回上一层");
                scanf("%d",&dChoose);
                if (dChoose==123)
                {
                    continue;
                }
                else
                    for (int m=0; m<LENTH; m++)                 //k是找卖家
                    {
                        for ( int k=0; k<LENTH; k++)
                        {
                            if (dChoose==ddishid[m]&&dshopid[m]==sellArr[k].shopid)
                            {
                                printf("您选择的是:");
                                for ( int i=0; i<LENTH; i++)
                                {
                                    for (int a=0; a<LENTH; a++)
                                    {
                                        
                                        if (dish1[i][k].dishname[a]==ddishname[m][a])
                                        {
                                            printf("%c",dish1[i][k].dishname[a]);
                                            d=i;
                                            continue;
                                        }
                                        else
                                            break;
                                    }
                                    
                                }
                                for (int j=0; j<20; j++)
                                {
                                    if (dingArr[j].dingdanid==0)
                                    {
                                        dingArr[j].dingdanid=sellArr[k].shopid+(dingdan+1)*1000;
                                        dingdan++;
                                        
                                        dingArr[j].shijiprice+=dish1[d][k].price;
                                        dingArr[j].dshopid=sellArr[k].shopid;
                                        strcpy(dingArr[j].dbuyername,buyname);
                                        strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                        strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                        dingdan_arr(dingArr);
                                        
                                        if(pay(dingArr[j].shijiprice, buyArr,buyname)==1)
                                        {  printf("\n订单信息为:%d,%d,%d,%s,%s\n",dingArr[j].dingdanid,dingArr[j].shijiprice,dingArr[j].dshopid,dingArr[j].ddishname,dingArr[j].dbuyername);
                                            return ;}
                                        else
                                        {
                                            printf("\n余额不足\n");
                                            return ;
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                break;
            }
            case 2:
            {
                for (int i=0; i<LENTH; i++)
                {
                    for (int j=0; j<LENTH; j++)
                    {
                        if (dish1[i][j].price>100&&dish1[i][j].price<=200)
                        {
                            printf("%d ",dn);
                            printf("%s,%d,%d\n",dish1[i][j].dishname,dish1[i][j].price,sellArr[j].shopid);
                            ddishid[m]=dn;
                            dshopid[m]=sellArr[j].shopid;
                            for (int a=0; a<LENTH; a++)
                            {
                                ddishname[m][a]=dish1[i][j].dishname[a];
                            }
                            m++;
                            dn++;
                            break;
                        }
                        else
                            break;
                    }
                }
                printf("请选择菜肴或输入123返回上一层");
                scanf("%d",&dChoose);
                if (dChoose==123) {
                    continue;
                }
                else
                    for (int m=0; m<LENTH; m++)
                    {
                        for ( int k=0; k<LENTH; k++)
                        {
                            if (dChoose==ddishid[m]&&dshopid[m]==sellArr[k].shopid)
                            {
                                printf("您选择的是:");
                                for ( int i=0; i<LENTH; i++)
                                {
                                    for (int a=0; a<LENTH; a++)
                                    {
                                        if (dish1[i][k].dishname[a]==ddishname[m][a])
                                        {
                                            printf("%c",dish1[i][k].dishname[a]);
                                            d=i;
                                            continue;
                                        }
                                        else
                                            break;
                                    }
                                }
                                for (int j=0; j<20; j++)
                                {
                                    if (dingArr[j].dingdanid==0)
                                    {
                                        dingArr[j].dingdanid=sellArr[k].shopid+(dingdan+1)*1000;
                                        dingdan++;
                                        dingArr[j].shijiprice+=dish1[d][k].price;
                                        dingArr[j].dshopid=sellArr[k].shopid;
                                        strcpy(dingArr[j].dbuyername,buyname);
                                        strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                        strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                        dingdan_arr(dingArr);
                                        
                                        if(pay(dingArr[j].shijiprice, buyArr,buyname)==1)
                                        {  printf("\n订单信息为:%d,%d,%d,%s,%s\n",dingArr[j].dingdanid,dingArr[j].shijiprice,dingArr[j].dshopid,dingArr[j].ddishname,dingArr[j].dbuyername);
                                            return ;}
                                        else
                                        {   printf("\n余额不足\n");
                                            return ;}
                                        
                                    }
                                }
                            }
                        }
                    }
                break;
            }
            case 3:
            {
                for (int i=0; i<LENTH; i++)
                {
                    for (int j=0; j<LENTH; j++)
                    {
                        if (dish1[i][j].price>200)
                        {
                            printf("%d ",dn);
                            printf("%s,%d,%d\n",dish1[i][j].dishname,dish1[i][j].price,sellArr[j].shopid);                    ddishid[m]=dn;
                            dshopid[m]=sellArr[j].shopid;
                            for (int a=0; a<LENTH; a++)
                            {
                                ddishname[m][a]=dish1[i][j].dishname[a];
                            }
                            m++;
                            dn++;
                            break;
                        }
                        else
                            break;
                    }
                }
                printf("请选择菜肴或输入123返回上一层");
                scanf("%d",&dChoose);
                if (dChoose==123)
                {
                    continue;
                }
                else
                    for (int m=0; m<LENTH; m++)
                    {
                        for ( int k=0; k<LENTH; k++)
                        {
                            if (dChoose==ddishid[m]&&dshopid[m]==sellArr[k].shopid)
                            {
                                printf("您选择的是:");
                                for ( int i=0; i<LENTH; i++)
                                {
                                    for (int a=0; a<LENTH; a++)
                                    {
                                        if (dish1[i][k].dishname[a]==ddishname[m][a])
                                        {
                                            printf("%c",dish1[i][k].dishname[a]);
                                            d=i;
                                            continue;
                                        }
                                        else
                                            break;
                                    }
                                    
                                }
                                for (int j=0; j<20; j++)
                                {
                                    if (dingArr[j].dingdanid==0)
                                    {
                                        dingArr[j].dingdanid=sellArr[k].shopid+(dingdan+1)*1000;
                                        dingdan++;
                                        dingArr[j].shijiprice+=dish1[d][k].price;
                                        dingArr[j].dshopid=sellArr[k].shopid;
                                        strcpy(dingArr[j].dbuyername,buyname);
                                        strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                        strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                        dingdan_arr(dingArr);
                                        
                                        if(pay(dingArr[j].shijiprice, buyArr,buyname)==1)
                                        {  printf("\n订单信息为:%d,%d,%d,%s,%s\n",dingArr[j].dingdanid,dingArr[j].shijiprice,dingArr[j].dshopid,dingArr[j].ddishname,dingArr[j].dbuyername);
                                            return ;}
                                        else
                                        {   printf("\n余额不足\n");
                                            return ;}
                                    }
                                }
                            }
                        }
                    }
                break;
            }
            default:
                break;
        }
    }while(1);
    
}
void queryByCook(char buyname[])
{
    char cookname[LENTH];
    int dn=0;
    int m=0;
    int ddishid[LENTH];
    int dshopid[LENTH];
    char ddishname[LENTH][LENTH];
    int dChoose;
    int d=0;
    do{
        for (int i=0; i<LENTH; i++) {
            for (int j=0; j<LENTH; j++) {
                if (strcmp(dish1[i][j].cook.cookname,"")!=0) {
                    printf("%s,%s,%d\n",dish1[i][j].cook.cookname,dish1[i][j].dishname,sellArr[j].shopid);
                }
            }
        }
        printf("请输入厨师姓名或输入123返回上一层:");
        scanf("%s",cookname);
        if (!strcmp(cookname, "123"))
        {
            return ;
        }
        else
        {
            for (int i=0; i<LENTH; i++)
            {
                for (int j=0; j<LENTH; j++)
                {
                    if (strcmp(dish1[i][j].cook.cookname,cookname)==0)
                    {
                        printf("%d ",dn);
                        printf("%s,%d,%d\n",dish1[i][j].dishname,sellArr[j].shopid,dish1[i][j].price);
                        ddishid[m]=dn;
                        dshopid[m]=sellArr[j].shopid;
                        for (int a=0; a<LENTH; a++)
                        {
                            ddishname[m][a]=dish1[i][j].dishname[a];
                        }
                        m++;
                        dn++;
                        break;
                    }
                }
            }
            printf("请选择菜肴或输入123返回上一层");
            scanf("%d",&dChoose);
            if (dChoose==123)
            {
                continue;
            }
            else
            {
                for (int m=0; m<LENTH; m++)
                {
                    for ( int k=0; k<LENTH; k++)
                    {
                        if (dChoose==ddishid[m]&&dshopid[m]==sellArr[k].shopid)
                        {
                            printf("您选择的是:");
                            for ( int i=0; i<LENTH; i++)
                            {
                                for (int a=0; a<LENTH; a++)
                                {
                                    if (dish1[i][k].dishname[a]==ddishname[m][a])
                                    {
                                        printf("%c",dish1[i][k].dishname[a]);
                                        d=i;
                                        continue;
                                    }
                                    else
                                        break;
                                }
                            }
                            for (int j=0; j<20; j++)
                            {
                                if (dingArr[j].dingdanid==0)
                                {
                                    dingArr[j].dingdanid=sellArr[k].shopid+(dingdan+1)*1000;
                                    dingdan++;
                                    
                                    dingArr[j].shijiprice+=dish1[d][k].price;
                                    dingArr[j].dshopid=sellArr[k].shopid;
                                    strcpy(dingArr[j].dbuyername,buyname);
                                    strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                    strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                    dingdan_arr(dingArr);
                                    
                                    if(pay(dingArr[j].shijiprice, buyArr,buyname)==1)
                                    {  printf("\n订单信息为:%d,%d,%d,%s,%s\n",dingArr[j].dingdanid,dingArr[j].shijiprice,dingArr[j].dshopid,dingArr[j].ddishname,dingArr[j].dbuyername);
                                        return ;}
                                    else
                                    {   printf("\n余额不足\n");
                                        return ;}
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }while(1);
}
void queryByAddress(char buyname[])
{
    char address[LENTH];
    int dn=0;
    int m=0;
    int ddishid[LENTH];
    int dshopid[LENTH];
    char ddishname[LENTH][LENTH];
    int dChoose;
    int d=0;
    
    do{
        for (int i=0; i<LENTH; i++) {
            if (strcmp(sellArr[i].shopaddress,"")) {
                printf("%s,%d\n",sellArr[i].shopaddress,sellArr[i].shopid);
            }
        }
        printf("请输入地区或输入123返回上一层");
        scanf("%s",address);
        if (!strcmp(address, "123"))
        {
            return ;
        }
        else
            
            for (int i=0;i<LENTH; i++)
            {
                for (int j=0; j<LENTH; j++)
                {
                    if (strcmp(sellArr[i].shopaddress,address)==0&&strcmp(dish1[j][i].dishname,""))
                    {
                        printf("%d ",dn);
                        printf("%s,%d,%d,%s\n",dish1[j][i].dishname,sellArr[i].shopid,dish1[j][i].price,dish1[j][i].cook.cookname);
                        ddishid[m]=dn;
                        dshopid[m]=sellArr[i].shopid;
                        for (int a=0; a<LENTH; a++)
                        {
                            ddishname[m][a]=dish1[j][i].dishname[a];
                        }
                        m++;
                        dn++;
                    }
                }
            }
        printf("请选择菜肴或输入123返回上一层");
        scanf("%d",&dChoose);
        if (dChoose==123)
        {
            continue;
        }
        else
            for (int m=0; m<LENTH; m++)
            {
                if (dChoose==ddishid[m])
                {
                    for ( int k=0; k<LENTH; k++)
                    {
                        if(dshopid[m]==sellArr[k].shopid)
                        {
                            printf("您选择的是:");
                            for ( int i=0; i<LENTH; i++)
                            {
                                for (int a=0; a<LENTH; a++)
                                {
                                    if (dish1[i][k].dishname[a]==ddishname[m][a])
                                    {
                                        printf("%c",dish1[i][k].dishname[a]);
                                        d=i;
                                        continue;
                                    }
                                    else
                                        break;
                                }
                                
                            }
                            for (int j=0; j<20; j++)
                            {
                                if (dingArr[j].dingdanid==0)
                                {
                                    dingArr[j].dingdanid=sellArr[k].shopid+(dingdan+1)*1000;
                                    dingdan++;
                                    
                                    dingArr[j].shijiprice+=dish1[d][k].price;
                                    dingArr[j].dshopid=sellArr[k].shopid;
                                    strcpy(dingArr[j].dbuyername,buyname);
                                    strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                    strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                                    dingdan_arr(dingArr);
                                    
                                    if(pay(dingArr[j].shijiprice, buyArr,buyname)==1)
                                    {  printf("\n订单信息为:%d,%d,%d,%s,%s\n",dingArr[j].dingdanid,dingArr[j].shijiprice,dingArr[j].dshopid,dingArr[j].ddishname,dingArr[j].dbuyername);
                                        return ;}
                                    else
                                    {   printf("\n余额不足\n");
                                        return ;}
                                    
                                }
                            }
                        }}
                }
            }
    }while(1);
}

//void queryByDiscount();
void queryOld()
{
    int flag=0;
    for (int i=0; i<LENTH; i++) {
        if (dingArr[i].ifreceive==1) {
            printf("%d,%d,%d\n",dingArr[i].dingdanid,dingArr[i].dshopid,dingArr[i].shijiprice);
            flag=1;
            return;
        }
        
    }
    if (flag==0) {
        printf("没有历史订单\n");
    }
    
}
void queryNoRecive()
{
    for (int i=0; i<LENTH; i++) {
        if (dingArr[i].ifsongdao==0&&dingArr[i].dingdanid!=0) {
            printf("%d,%d,%d\n",dingArr[i].dingdanid,dingArr[i].dshopid,dingArr[i].shijiprice);
            
        }
    }
    return;
}
void queryDish(char shopkind[],char buyname[])
{
    int dn=0;  //显示菜品时的编号
    int m=0;    //
    int ddishid[LENTH];//
    int dshopid[LENTH];//
    char ddishname[LENTH][LENTH];//
    int dChoose;//输入的餐厅编号
    int d=0;//
    int n[LENTH];//存显示餐厅编号时，重新编号的餐厅的编号
    int sChoose;//
    int shopidCount=0;//
    
    do
    {
        
        for (int i=0; i<LENTH; i++)
        {
            if (!strcmp(sellArr[i].sort.sortname, shopkind))
            {
                printf("%d\n",sellArr[i].shopid);
                n[shopidCount]=i;    //保存该种类商店的数据元素下标索引
                shopidCount++;       //存储该种类商店的总数
            }
        }
        
        //输入餐厅编号并判断
        printf("请输入选择的餐厅编号或输入123返回上一层:\n");
        scanf("%d",&sChoose);
        if (sChoose==123) {
            return ;    //结束调用
        }
        else
        {
            dn=0; //初始化菜品编号
            //循环输出该餐厅的菜品信息
            for (int i = 0 ; i<shopidCount; i++)
            {
                if (sChoose==sellArr[n[i]].shopid)
                {
                    //循环查找用户所选餐厅，输出该餐厅菜品信息
                    for (int j = 0 ; j<LENTH; j++)
                    {
                        if (strcmp(dish1[j][n[i]].dishname,""))
                        {
                            //输出菜品编号
                            printf("%d ",dn);
                            //输出菜品信息，设计时要求二维菜品结构体数组中，每列的菜品与该餐厅信息结构体对应元素的数组索引相同
                            printf("%s,%d,%s\n",dish1[j][n[i]].dishname,dish1[j][n[i]].price,dish1[j][n[i]].cook.cookname);
                            ddishid[m]=dn;
                            dshopid[m]=sellArr[n[i]].shopid;
                            
                            for (int a=0; a<LENTH; a++)
                            {
                                ddishname[m][a]=dish1[j][n[i]].dishname[a];
                            }
                            m++;
                            dn++;
                        }
                    }
                    break;
                }
            }
            
            printf("请选择菜肴或输入123返回上一层:\n");
            scanf("%d",&dChoose);
            if (dChoose!=123) {
                break;
            }
        }
    }while (1);
    
    
    for (int m=0; m<LENTH; m++)
    {
        for ( int k=0; k<LENTH; k++)
        {
            if (dChoose==ddishid[m]&&dshopid[m]==sellArr[k].shopid)
            {
                printf("您选择的是:");
                for ( int i=0; i<LENTH; i++)
                {
                    for (int a=0; a<LENTH; a++)
                    {
                        if (dish1[i][k].dishname[a]==ddishname[m][a])
                        {
                            printf("%c",dish1[i][k].dishname[a]);
                            d=i;
                            continue;
                        }
                        else
                            break;
                    }
                }
                for (int j=0; j<20; j++)
                {
                    if (dingArr[j].dingdanid==0)
                    {
                        dingArr[j].dingdanid=sellArr[k].shopid+(dingdan+1)*1000;
                        dingdan++;
                        
                        dingArr[j].shijiprice+=dish1[d][k].price;
                        dingArr[j].dshopid=sellArr[k].shopid;
                        strcpy(dingArr[j].dbuyername,buyname);
                        strcpy(dingArr[j].ddishname,dish1[d][k].dishname);
                        dingdan_arr(dingArr);
                        
                        if(pay(dingArr[j].shijiprice, buyArr,buyname)==1)
                        {  printf("\n订单信息为:%d,%d,%d,%s,%s\n",dingArr[j].dingdanid,dingArr[j].shijiprice,dingArr[j].dshopid,dingArr[j].ddishname,dingArr[j].dbuyername);
                            return ;}
                        else
                        {   printf("\n余额不足\n");
                            return ;}
                    }
                }
            }
        }
    }
    
    
    
    return ;
}

int pay(int price,struct Buyman buyArr[],char buyname[])
{
    for (int i=0; i<LENTH; i++) {
        if (strcmp(buyArr[i].buymanname,buyname)==0) {
            if (buyArr[i].buymanmoney<price) {
                
                return 0;
            }
            else
            {
                buyArr[i].buymanmoney-=price;
                buyman_arr(buyArr);
                
                printf("\n付款成功!\n");
                return 1;}
        }
    }
    return 0;
}
void queryMList(int shopid)
{
    for (int i=0; i<LENTH; i++) {
        if (dingArr[i].dshopid==shopid) {
            printf("%d,%s,%d\n",dingArr[i].dingdanid,dingArr[i].ddishname,dingArr[i].shijiprice);
        }
    }
}
void showselljiemian(int shopid)                            //卖家界面
{   while(1)
{
    int a;
    printf("***************************");
    printf("\n");
    printf("\n");
    printf("    欢迎亲爱的卖家回来！    ");
    printf("\n");
    printf("\n");
    printf("    1.更新菜单    ");
    printf("\n");
    printf("\n");
    printf("    2.接单    ");
    printf("\n");
    printf("\n");
    printf("    3.更改订单状态   ");
    printf("\n");
    printf("\n");
    printf("    4.查询订单状态    ");
    printf("\n");
    printf("\n");
    printf("    5.查询历史账单    ");
    printf("\n");
    printf("\n");
    printf("    6.查询评价    ");
    printf("\n");
    printf("\n");
    printf("***************************");
    printf("\n");
    printf("请选择您要选择的状态或者按0返回上一层");
    scanf("%d",&a);
    switch (a)
    {
        case 1:showdishgengxin(shopid);break;//更新菜单
        case 2:jiedan(shopid); break;//接单
        case 3:genggaidingdanzhuangtai(shopid);break;//更改订单状态
        case 4:chaxundingdanzhuangtai(shopid);break;//查询订单状态
        case 5:showhistoryzhangdan(shopid); break;//查询历史账单
        case 6:showchaxunpingjia(shopid);break;//查询评价
            
        case 0: return;
            
    }
    
}}

void showdishgengxin(int shopid)                                    //更新菜单

{
    while (1) {
        
        int a;
        printf("***************************");
        printf("\n");
        printf("\n");
        printf("    欢迎亲爱的卖家回来！    ");
        printf("\n");
        printf("\n");
        printf("    1.添加菜品    ");
        printf("\n");
        printf("\n");
        printf("    2.更改菜品余量    ");
        printf("\n");
        printf("\n");
        printf("    3.更改价格  ");
        printf("\n");
        printf("\n");
        printf("    4.更改厨师    ");
        printf("\n");
        printf("\n");
        printf("    5.更改商店类型    ");
        printf("\n");
        printf("\n");
        printf("    6.更改地址    ");
        printf("\n");
        printf("\n");
        printf("***************************");
        printf("\n");
        printf("请选择您要选择的状态或者按0返回上一层");
        scanf("%d",&a);
        switch (a)
        {
            case 1:addcaipin(shopid);break;//添加菜品
            case 2:genggaicaipinyuliang(shopid);  break;//更改菜品余量
            case 3:genggaijiage(shopid);break;//更改价格
            case 4:genggaichushi(shopid);break;//更改厨师
            case 5:genggaishopleixing(shopid); break;//更改商店类型
            case 6:genggaiaddress(shopid);break;//更改地址
            case 0:return;
        }
        
    }}


void showhistoryzhangdan(int shopid)      //查询历史订单
{   while(1)
{
    int a;
    printf("***************************");
    printf("\n");
    printf("\n");
    printf("    欢迎亲爱的卖家回来！    ");
    printf("\n");
    printf("\n");
    printf("    1.查询收支情况    ");
    printf("\n");
    printf("\n");
    printf("    2.查询订单情况    ");
    printf("\n");
    printf("\n");
    printf("***************************");
    printf("\n");
    printf("请选择您要选择的状态或者按0返回上一层");
    scanf("%d",&a);
    switch (a)
    {
        case 1:chaxunshouzhiqingkuakng(shopid);break;//查询收支情况
        case 2:queryMList(shopid);break;//查询订单情况
        case 0:return;
    }
}}

void showchaxunpingjia(int shopid)
{   while(1)
{
    int a;
    printf("***************************");
    printf("\n");
    printf("\n");
    printf("    欢迎亲爱的卖家回来！    ");
    printf("\n");
    printf("\n");
    printf("    1.查询菜品评价    ");
    printf("\n");
    printf("\n");
    printf("    2.查询厨师评价    ");
    printf("\n");
    printf("\n");
    // printf("    3.查询送餐评价  ");
    // printf("\n");
    // printf("\n");
    printf("***************************");
    printf("\n");
    printf("请选择您要选择的状态或者按0返回上一层");
    scanf("%d",&a);
    switch (a)
    {
        case 1:chaxundishpingjia(shopid);break;//查询菜品评价
        case 2:chaxuncookpingjia(shopid);break;//查询厨师评价
        case 0:return;break;
            
            
            
    }
}}
int addcaipin(int shopid)            //添加菜品功能
{   int i,j,a;
    char dishname[LENTH];         //菜肴名字
    int price=0;                    //菜肴价格
    int suoshengnumber=0;           //菜肴所剩数量
    char dishmiaoshu[LENTH];        //菜肴描述
    char cookname[LENTH];         //厨师姓名
    char cookjudge[LENTH];        //厨师评价
    printf("请输入菜肴名字：");
    scanf("%s",dishname);
    printf("请输入菜肴价格：");
    scanf("%d",&price);
    printf("请输入菜肴所剩数量：");
    scanf("%d",&suoshengnumber);
    printf("请输入菜肴描述：");
    scanf("%s",dishmiaoshu);
    printf("请输入厨师姓名：");
    scanf("%s",cookname);
    printf("请输入厨师评价：");
    scanf("%s",cookjudge);
    for(j=0;j<LENTH;j++)
    {
        if (sellArr[j].shopid==shopid)               //找到更新菜单的商店
        {
            
            for(i=0;i<LENTH;i++)
            {   if(dish1[i][j].price==0)           //价钱为零时，加入更新内容
            {
                strcpy(dish1[i][j].dishname,dishname);
                dish1[i][j].price=price;
                dish1[i][j].suoshengnumber=suoshengnumber;
                strcpy(dish1[i][j].dishmiaoshu,dishmiaoshu);
                strcpy(dish1[i][j].cook.cookname,cookname);
                strcpy(dish1[i][j].cook.cookjudge,cookjudge);
                printf("%s\n%d\n%d\n%s\n%s\n%s\n",dish1[i][j].dishname,dish1[i][j].price,dish1[i][j].suoshengnumber,dish1[i][j].dishmiaoshu,dish1[i][j].cook.cookname,dish1[i][j].cook.cookjudge);       //更新后输出新添加的菜品
                dish_arr(dish1);
                printf("按0返回上一层");
                scanf("%d",&a);
                switch (a){
                    case 0:
                        return 0;
                        break;
                }
                
                return 1;
            }}}
    }  return 0;
    
}


void genggaicaipinyuliang(int shopid)                  //更新菜品余量
{   int i,j;
    char dishname[LENTH];
    int suoshengnumber=0;
    printf("请输入菜肴名字：");
    scanf("%s",dishname);
    for(j=0;j<LENTH;j++)
    {
        if (sellArr[j].shopid==shopid)       //找到商店
        {
            for(i=0;i<LENTH;i++)
            {
                if((strcmp(dish1[i][j].dishname,dishname))==0)       //找到菜品，准备进行更新
                {   printf("请输入菜品余量：");
                    scanf("%d",&suoshengnumber);
                    dish1[i][j].suoshengnumber=suoshengnumber;
                    printf("菜品数量更改成功！");
                    printf("目前数量是:%d\n",dish1[i][j].suoshengnumber);break;
                    dish_arr(dish1);
                }
            }}}
}

void genggaijiage(int shopid)            //更新菜品价格
{
    int i,j;
    char dishname[LENTH];
    int price=0;
    printf("请输入菜肴名字：");
    scanf("%s",dishname);
    for(j=0;j<LENTH;j++)
    {
        if (sellArr[j].shopid==shopid)       //找到商店
        {
            
            for(i=0;i<LENTH;i++)
            {
                if((strcmp(dish1[i][j].dishname,dishname))==0)        //找到菜品
                {   printf("请输入菜品余价格：");
                    scanf("%d",&price);
                    dish1[i][j].price=price;//对菜品价格进行更新
                    printf("菜品价格更改成功！\n");
                    printf("目前的价格是:%d\n",dish1[i][j].price);
                    dish_arr(dish1);
                    return;
                }
            }}}
}

void genggaichushi(int shopid)       //更改厨师
{   int i,j;
    char cookname[LENTH];
    char dishname[LENTH];
    printf("请输入菜肴名字：");
    scanf("%s",dishname);
    for(j=0;j<LENTH;j++)
    {
        if (sellArr[j].shopid==shopid)
        {
            
            for(i=0;i<LENTH;i++)
            {
                if((strcmp(dish1[i][j].dishname,dishname))==0)
                {   printf("请输入厨师姓名：");
                    scanf("%s",cookname);
                    strcpy(dish1[i][j].cook.cookname,cookname);
                    printf("更改厨师姓名成功！\n");
                    printf("新的厨师姓名是:%s\n",dish1[i][j].cook.cookname);
                    dish_arr(dish1);
                    return;
                }
                
                
                
            }}}}
void genggaishopleixing(int shopid)//更改商店类型
{   int i;
    int shopkind;
    for(i=0;i<LENTH;i++)
    {   if(sellArr[i].shopid==shopid)
    {printf("请输入商店类型：");
        scanf("%d",&shopkind);
       sellArr[i].sort.sortnumber=shopkind;
        strcpy(sellArr[i].sort.sortname,sortArr[shopkind-1].sortname);
        printf("更改商店类型成功！\n");
        printf("新的商店类型是:%d %s\n", sellArr[i].sort.sortnumber,sellArr[i].sort.sortname);
        sellman_arr(sellArr);
        return;
    }
    }
    
}

void genggaiaddress(int shopid)           //更改商店地址
{
    int i;
    char shopaddress[LENTH];
    for(i=0;i<LENTH;i++)
    {   if(sellArr[i].shopid==shopid)
    {printf("请输入商店地址：");
        scanf("%s",shopaddress);
        strcpy(sellArr[i].shopaddress,shopaddress);
        printf("更改商店地址成功！");
        printf("新的商店地址是:%s\n",sellArr[i].shopaddress);
        sellman_arr(sellArr);
        return;
    }
    }
}

void chaxunshouzhiqingkuakng(int shopid)  //查询收支情况
{   int i,k;int sum1=0;int sum2=0;int sum3=0;
    for(k=0;k<LENTH;k++)
    {
        if (sellArr[k].shopid==shopid)
        {
            for(i=0;i<LENTH;i++)
                // { for(j=0;j<LENTH;j++)
                
            {   if(dingArr[i].ifreceive==1)
            {
                // if( strcmp(dingArr[i].ddishname,dish1[j][k].dishname)==0)
                //{
                sum1=dingArr[i].shijiprice+sum1;
                
                //}
                //}
            }}}}
    sum2=sum1*0.01;
    sum3=sum1-sum2;
    printf("总共的支出为：%d\n",sum2);
    printf("总共的收入为：%d\n",sum3);
}

void chaxundishpingjia(int shopid)         //查询菜品评价
{int i,k;
    char dishname[LENTH];
    printf("请输入菜肴名字：");
    scanf("%s",dishname);
    for(k=0;k<LENTH;k++)
    {
        if (sellArr[k].shopid==shopid)
        {
            for(i=0;i<LENTH;i++)
            {
                if((strcmp(dish1[i][k].dishname,dishname))==0)
                {
                    printf("菜肴评价是:%s\n",dish1[i][k].dishjudge);
                    dish_arr(dish1);
                }
                
            }
        }
    }
    
}

void chaxuncookpingjia(int shopid)        //查询厨师评价
{
    int i,k;
    char cookname[LENTH];         //厨师姓名
    printf("请输入厨师姓名：");
    scanf("%s",cookname);
    for(k=0;k<LENTH;k++)
    {
        if (sellArr[k].shopid==shopid)
        {
            for(i=0;i<LENTH;i++)
            {
                if((strcmp(dish1[i][k].cook.cookname,cookname))==0)
                {
                    printf("对厨师的评价是:%s\n",dish1[i][k].cook.cookjudge);
                    dish_arr(dish1);
                    break;
                }
            }
        }
    }
}

int jiedan(int shopid)                    //接单
{
    
    int i;int a=1;
    int flag=0;
    printf("是否接单：接单请输入1，不接单请输入0！");
    while(1)
    {   scanf("%d",&a);
        if(a!=1&&a!=0)
        {printf("您输入的有错误，请重新输入");
            continue;}
        else if(a==0)
        {
            showselljiemian(shopid);return 0;     //不接单直接返回主界面    传入订单号
        }
        
        for(i=0;i<LENTH;i++)
        {
            if (dingArr[i].dshopid==shopid&&dingArr[i].ifjiedan!=1) {
                //dingArr[i].dingdanid=dingdanid;
                printf("***************************");
                printf("\n");
                printf("\n");
                printf("    欢迎亲爱的卖家回来！    ");
                printf("\n");
                printf("\n");
                printf("    您的订单号是：%d\n",dingArr[i].dingdanid);    //输出订单
                printf("    买家实际交付的价钱：%d\n",dingArr[i].shijiprice);
                printf("    卖家的商店编号：%d\n",dingArr[i].dshopid);
                printf("    买家的姓名是：%s\n",dingArr[i].dbuyername);
                printf("    买家订的菜肴名称是：%s\n",dingArr[i].ddishname);
                printf("***************************");
                printf("\n");
                printf("\n");
                flag=1;
                dingArr[i].ifjiedan=1;
                dingdan_arr(dingArr);
                printf("请输入1继续接单或输入0返回");
                int n;
                scanf("%d",&n);
                if (n==1) {
                    continue;
                }
                else if (n==0)
                    
                    return 0;
                }
            else
            {
                flag=0;
            }
        }
        
        if (flag==0) {
            printf("没有新订单\n");
            return 0;
        }
    }
    
}

void genggaidingdanzhuangtai(int shopid)  //更改订单状态
{
    
    int i,a;
    int flag=0;
    for(i=0;i<LENTH;i++)
    {
        if(dingArr[i].dingdanid!=0&&dingArr[i].ifyizuo!=1&&dingArr[i].dshopid==shopid&&dingArr[i].ifjiedan==1)
        { printf("***************************");
            printf("\n");
            printf("\n");
            printf("    欢迎亲爱的卖家回来！    ");
            printf("\n");
            printf("\n");
            printf("    您的订单号是：%d\n",dingArr[i].dingdanid);
            printf("    买家实际交付的价钱：%d\n",dingArr[i].shijiprice);
            printf("    卖家的商店编号：%d\n",dingArr[i].dshopid);
            printf("    买家的姓名是：%s\n",dingArr[i].dbuyername);
            printf("    买家订的菜肴名称是：%s\n",dingArr[i].ddishname);
            printf("***************************");
            printf("\n");
            printf("\n");
            if(dingArr[i].ifreceive==1)
                return;
            if(dingArr[i].dingdanid==0)
            {   printf("没有符合情况的订单！\n");
                return ;}
            printf("是否已做，1代表做了，0代表没有做。");
            while(1)
            {
                scanf("%d",&a);
                if(a!=0&&a!=1)
                {
                    printf("您输入的有错误，请重新输入");
                    continue;
                }else if(a==1)
                    
                {   printf("买家订的饭菜已做");
                    dingArr[i].ifyizuo=a;
                    flag=1;
                    dingdan_arr(dingArr);
                    printf("请输入1继续更新订单或输入0返回");
                    int n;
                    scanf("%d",&n);
                    if (n==1) {
                        break;
                    }
                    else if (n==0)
                        
                        return ;
                }
                else if (a==0)
                {
                    printf("买家订的饭菜未做");
                    dingArr[i].ifyizuo=a;
                    dingdan_arr(dingArr);
                    printf("请输入1继续更新订单或输入0返回");
                    int n;
                    scanf("%d",&n);
                    if (n==1) {
                        break;
                    }
                    else if (n==0)
                        return ;
                }
            }
            continue;}
        else
        {
            flag=0;
           
        }
    }
    if (flag==0) {
         printf("没有符合条件的订单\n");
        return;
    }
    return ;
}

void chaxundingdanzhuangtai(int shopid)     //查询订单状态
{
    int i;
    int flag=0;
    printf("***************************");
        printf("\n");
        printf("\n");
        printf("    欢迎亲爱的卖家回来！    ");
        printf("\n");
        printf("\n");
    for(i=0;i<LENTH;i++)
    {
        
        
       
        if(dingArr[i].ifjiedan==1)
        {
        if(dingArr[i].dingdanid==0||dingArr[i].dshopid!=shopid)
        {   flag=0;
            printf("没有符合情况的订单！\n");
            return ;}
        
        else if(dingArr[i].ifreceive==1)
        {printf("   买家已经收货\n");
            return;
            flag=1;}
        else
        { printf("   正在途中请稍候\n");
            printf("   买家还没有收货\n");
            printf("    您的订单号是：%d\n",dingArr[i].dingdanid);
            printf("    买家实际交付的价钱：%d\n",dingArr[i].shijiprice);
            printf("    卖家的商店编号：%d\n",dingArr[i].dshopid);
            printf("    买家的姓名是：%s\n",dingArr[i].dbuyername);
            printf("    买家订的菜肴名称是：%s\n",dingArr[i].ddishname);
            
            printf("***************************");
            printf("\n");
            printf("\n");
            printf("请输入1继续查询订单或输入0返回");
            flag=1;
            int n;
            scanf("%d",&n);
            if (n==1) {
                continue;
            }
            else if (n==0)
                return ;
        }
    }
        }
    
    
    return;
}

int n;

void mainMenu()
{
    
    do{ printf("\t\t\t欢迎使用天天外卖系统\t\t\t\n\n");
        printf("**********************************\n\n");
        printf("\t\t\t1. 卖家系统\t\t\t\n");
        printf("\t\t\t2. 买家系统\t\t\t\n");
        printf("\t\t\t3. 管理员系统\t\t\t\n\n");
        printf("请输入数字序号，选择进入:\n");
        int n;
        scanf("%d",&n);
        switch (n) {
            case 1:
                cseller();//卖家系统
                break;
            case 2:
                sbuyer();// 买家系统
                
                break;
            case 3:
                manager();//管理员系统
                break;
            default:
                //printf("输入错误，请您重新选择:\n");
                break;
        }
    }while(1);
    
}
void cseller()//卖家系统主菜单
{
    do{
        printf("天天外卖>> >> >> >>卖家系统\n\n");
        printf("\t\t\t1. 注册卖家账户\n");
        printf("\t\t\t2. 登录系统\n");
        printf("\t\t\t3. 查询注册情况\n");
        printf("请输入序号选定操作内容或按0返回上级菜单!");
        int a;
        scanf("%d",&a);
        switch (a) {
            case 1:
                registorSeller();//卖家注册
                break;
            case 2:
                loginSeller();//卖家登陆
                break;
            case 3:
                selectRegistor();//查询是否注册成功
                break;
            case 0:
                return;//调回主菜单
                break;
        }}while(1);
    
}

char username[LENTH];//定义成全局变量，方便后面addseller()中，赋值使用
int a1;
char storename[LENTH];
int b1;
char storeaddress[LENTH];
int flog=1;

void registorSeller()
{do{
    printf("请输入用户名:\n");//定义用户名
    
    scanf("%s",username);
    printf("请输入用户密码:\n");//定义用户密码
    
    scanf("%d",&a1);
    printf("请输入商店名称:\n");//定义商店名称
    
    scanf("%s",storename);
    printf("\t\t\t请选择商店种类:\t\t\n\n");//定义商店种类
    printf("\t\t\t1. 快餐\n");
    printf("\t\t\t2. 烧烤\n");
    printf("\t\t\t3. 火锅\n");
    printf("\t\t\t4. 甜品类\n");
    printf("\t\t\t5. 饮品类\n");
    
    scanf("%d",&b1);
    printf("请输入商店地址:\n");//定义商店地址
    
    scanf("%s",storeaddress);
    printf("请再次输入用户名:\n");//再次确认用户名
    char username2[LENTH];
    scanf("%s",username2);
    printf("请再次输入用户密码:\n");//再次确认用户密码
    int a2;
    scanf("%d",&a2);
    printf("请再次输入商店名称:\n");//再次确认商店名称
    char storename2[LENTH];
    scanf("%s",storename2);
    printf("\t\t\t请再次选择商店种类:\t\t\n\n");//再次确认商店种类
    printf("\t\t\t1. 快餐\n");
    printf("\t\t\t2. 烧烤\n");
    printf("\t\t\t3. 火锅\n");
    printf("\t\t\t4. 甜品类\n");
    printf("\t\t\t5. 饮品类\n");
    int b2;
    scanf("%d",&b2);
    printf("请再次输入地址:\n");//再次确认商店地址
    char storeaddress2[LENTH];
    scanf("%s",storeaddress2);
    if ((a1==a2)&&(!strcmp(username,username2))&&(!strcmp(storeaddress,storeaddress2))&&(b1==b2))//当都相等，则flog=1,等待管理员核实，退出
    {
        printf("您已成功申请，稍等片刻等待回应\n");
        for (int i=0; i<LENTH; i++) {
            if (strcmp(sellArr[i].uname,"")==0) {
                strcpy(sellArr[i].uname,username);
                                sellArr[i].ucode=a2;
                strcpy(sellArr[i].shopname,storename);
                strcpy(sellArr[i].shopaddress, storeaddress2);
                sellArr[i].sort.sortnumber=b2;
                strcpy( sellArr[i].sort.sortname, sortArr[b2-1].sortname);
                sellArr[i].ifzhuce=1;
                break;
            }        }
          sellman_arr(sellArr);
        break;
    }else{printf("输入错误，请重新输入\n");
        continue;
    }}while(1);
}
void loginSeller()//卖家登陆系统
{
    
    printf("请输入用户名:");//输入卖家用户名
    char u1[LENTH];
    scanf("%s",u1);
    printf("请输入用户密码:");//输入卖家用户密码
    int s1;
    scanf("%d",&s1);
    for (int i=0; i<=50; i++)
    {
        if (!(strcmp(sellArr[i].uname, u1))&&(sellArr[i].ucode==s1))
        {
            int shopid=sellArr[i].shopid;
            
            printf("卖家登陆成功!");//卖家登陆成功后，调用卖家功能菜单
            showselljiemian(shopid);
            return;
            
        }
        
    }
    
}
void selectRegistor()
{
    
    int flag=0;
    
    printf("请输入注册的用户名:\n");
    char ch[LENTH];
    scanf("%s",ch);
    //通过卖家自己注册时用的用户名，判断结构体中是否已有自己的信息，判断是否注册成功
    for (int i=0; i<=50; i++)
    { if ((strcmp(sellArr[i].uname,ch)==0)&&sellArr[i].ifzhuce==0)
        {
        printf("注册成功!\n");
        //注册成功后，将卖家的编号告诉给卖家
        if (i!=0) {
            printf("您的店铺编号为:%d\n",sellArr[i-1].shopid+1);
        }
        else
            printf("您的店铺编号为:1001\n");
        
        flag=1;
        break;
        
        }
    else{
        //当结构体中没有该卖家信息，注册失败。调用退出函数，退出。
        flag=0;
        }
    }
    if (flag==0) {
        printf("注册失败!");
        quit();
    }
}

void quit()//退出
{
    printf("退出成功，感谢您的使用!\n");
}
void sbuyer()//买家系统
{
    
    do{
        printf("欢迎登陆买家系统！\n");
        printf("天天外卖>> >> >> >>买家系统\n\n");
        printf("\t\t\t1. 注册买家账户\n");
        printf("\t\t\t2. 登录系统\n");
        printf("请输入编号进行操作或按0返回上级菜单:\n");
        int h;
        scanf("%d",&h);
        switch (h)
        {
            case 1:
                registorbuyer();
                break;
            case 2:
                loginbuyer();
                break;
            case 0:
                return ;
                break;
        }}while (1);
    
}
void registorbuyer()
{
    int flog=0;
    for(int j=0;j<=50;j++)
    {
        if(buyArr[j].bnumber==0)
        {
            for(int i=1;i<=3;i++)
            {
                printf("请您输入您的买家用户名称:\n");//买家设置用户名
                char buyername[LENTH];
                scanf("%s",buyername);
                printf("请输入您的买家用户密码(四位数字):\n");//买家设置用户密码
                int buyercode;
                scanf("%d",&buyercode);
                if((buyercode<=9999)&&(buyercode>=1000))
                {
                    printf("请您再次输入您的买家用户名称:\n");
                    char buyername2[LENTH];
                    scanf("%s",buyername2);
                    printf("请您再次输入您的买家用户密码:\n");
                    int buyercode2;
                    scanf("%d",&buyercode2);
                    if(!strcmp(buyername,buyername2)&&(buyercode==buyercode2))
                    {
                        strcpy(buyArr[j].bname,buyername);
                        buyArr[j].bcode=buyercode;
                        printf("请填入您的名字：\n");
                        char buyname[LENTH];
                        scanf("%s",buyname);
                        strcpy(buyArr[j].buymanname,buyname);
                        printf("请输入您的联系方式:\n");
                        long telenum;
                        scanf("%ld",&telenum);
                        buyArr[i].connect=telenum;
                        buyman_arr(buyArr);
                        printf("注册成功!");
                        flog=1;
                        return;
                    }
                }else if (!flog)
                {
                    printf("您输入的用户名与密码不匹配，请重新输入！\n");
                    printf("您还有%d次机会!",3-i);
                    
                }
            }
        }
    }
    
    
}
void loginbuyer()
{
    int flag=0;
    for (int j=1; j<=3; j++)
    {
        printf("请输入您的用户名：\n");
        char bbna[LENTH];
        scanf("%s",bbna);
        printf("请输入您的用户密码:\n");
        int cc;
        scanf("%d",&cc);
        for (int i=0; i<=50; i++)
        {
            if (!strcmp(buyArr[i].bname,bbna)&&buyArr[i].bcode==cc)
            {
                printf("登陆成功！\n");
                
                char buyname[LENTH];
                strcpy(buyname, buyArr[i].buymanname);
                buyer(buyname);//登陆成功后，显示菜单
                flag=1;
                return ;
                
                
            }else{
                flag=0;
                
            }
        }
        if (flag==0) {
            printf("您输入的用户名与密码不匹配，请重新输入！\n");
            printf("您还有%d次机会!",3-j);
        }
        else
            break;
    }
    return ;
    
}
void manager()//管理员系统
{
    do{
        
        printf("天天外卖>> >> >> >>管理员系统\n\n");
        printf("\t\t\t1. 管理员登陆\n");
        printf("\t\t\t2. 修改个人信息\n\n\n");
        printf("请输入数字序号，选择进入或输入0返回:");
        int a;
        scanf("%d",&a);
        switch (a)
        {
            case 1:
                managerLogin();//管理员登陆
                break;
            case 2:
                modifymanagerinfo();//修改个人信息
                break;
            case 0:
                return;
                break;
            default:
                quit();//选择退出
                break;
        }}while(1);
}
void managerLogin()
{
    printf("请输入管理员名称:\n");
    char managername[LENTH];
    scanf("%s",managername);
    printf("请输入管理员密码:\n");
    int managercode;
    scanf("%d",&managercode);
    for (int i=0; i<=5; i++)
    {
        if (!strcmp(managername, man[i].managername)&&(managercode==man[i].managercode))    //当管理员名称，密码都符合条件时，登陆成功
        {
            printf("登陆成功!\n");//管理员登陆成功
            managermenu();//管理员登陆成功后，调用管理员菜单，进行选择操作
            return;
        }
        
        
    } printf("登陆失败，返回上级菜单!\n");
}
void managermenu()//管理员登陆后的菜单
{
    do{
        printf("登陆成功！");
        printf("天天外卖>> >> >> >> >>管理员系统\n\n\n");
        printf("\t\t\t1. 添加卖家\n");
        printf("\t\t\t2. 添加买家\n");
        printf("\t\t\t3. 删除卖家\n");
        printf("\t\t\t4. 删除买家\n");
        printf("\t\t\t5. 修改卖家个人信息\n");
        printf("\t\t\t6. 制定优惠活动\n");
        //printf("\t\t\t6. 卖家等级评估\n\n\n");
        printf("请输入数字序号，选择进入或输入0返回:");
        int a;
        scanf("%d",&a);
        switch (a) {
            case 1:
                addseller();//添加卖家
                break;
            case 2:
                addbuyer();//添加买家
                break;
            case 3:
                deleseller();//删除卖家
                break;
            case 4:
                delebuyer();//删除买家
                break;
            case 5:
                modifySellerinfo();//管理员修改卖家个人信息
                break;
            case 6:
                active();
                break;
            case 0:
                return;
                break;
            default:
                //evaluate();//管理员对卖家进行评估
                break;
        }
    }while(1);
    
}
void addseller()
{
    int flag=0;
    for(int i=0;i<=LENTH;i++)
    {
        if (strcmp(sellArr[i].uname,"")!=0&&sellArr[i].ifzhuce==1)
        {
            printf("%s,%d,%s,%d,%s,%s\n",sellArr[i].uname,sellArr[i].ucode,sellArr[i].shopname,sellArr[i].sort.sortnumber,sortArr[sellArr[i].sort.sortnumber-1].sortname,sellArr[i].shopaddress);
            break;
        }
    }
    for(int j=0;j<=LENTH;j++)
    {
        if(sellArr[j].shopid==0&&sellArr[j-1].shopid!=0)
        {
            do
            {
                printf("请输入您要添加的用户名:\n");                 //判断用户名
                char mna[LENTH];
                scanf("%s",mna);
                for (int i=0; i<j; i++)
                {
                    if (strcmp( sellArr[i].uname,mna))
                    {
                        flag=0;}
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                if (flag==1) {
                    continue;
                }
                else{
                    strcpy(sellArr[j].uname,mna);
                    printf("请输入您要添加的用户密码:\n");
                    int f;
                    scanf("%d",&f);
                    sellArr[j].ucode=f;
                    printf("请输入您要添加的商店名称:\n") ;
                    char sna[LENTH];
                    scanf("%s",sna);
                    strcpy(sellArr[j].shopname,sna);
                    printf("请您输入您要添加的商店地址:\n");
                    char ad[LENTH];
                    scanf("%s",ad);
                    strcpy(sellArr[j].shopaddress,ad);
                    int ss;
                    do{  printf("请输入您要添加的商店种类：\n");
                        
                        scanf("%d",&ss);
                    }while(ss<1||ss>5);
                    
                    sellArr[j].sort.sortnumber=ss;
                    sellArr[j].ifzhuce=1;
                    if (j!=0) {
                        sellArr[j].shopid=sellArr[j-1].shopid+1;
                        printf("您的店铺编号为:%d\n",sellArr[j-1].shopid+1);
                    }
                    else
                    {
                        sellArr[j].shopid=1001;
                        printf("您的店铺编号为:1001\n");
                    }
                    sellman_arr(sellArr);
                    printf("添加用户成功！\n");
                    printf("请按0返回上级菜单:\n");
                    int o;
                    scanf("%d",&o);
                    if(o==0)
                    {
                        return;
                    }
                    
                    
                }
            }while (1);
            
        }
        
        
    }

}
void addbuyer()                      // 添加买家
{
    for (int i=0; i<=50; i++)
    {
        if (buyArr[i].bnumber==0)
        {
            printf("请输入您要添加的买家用户名:\n");
            char adname[20];
            scanf("%s",adname);
            printf("请输入您要添加的买家用户密码:\n");
            int adcode;
            scanf("%d",&adcode);
            printf("请输入您要添加的买家姓名:\n");
            char arname[20];
            scanf("%s",arname);
            printf("请输入您要添加的买家联系方式:\n");
            long adconnect;
            scanf("%ld",&adconnect);
            printf("请输入您要添加的买家地址:\n");
            char address[LENTH];
            scanf("%s",address);
            strcpy(buyArr[i].bname,adname);
            buyArr[i].bcode=adcode;
            strcpy(buyArr[i].buymanname, arname);
            buyArr[i].connect=adconnect;
            strcpy(buyArr[i].buymanaddress,address);
            buyman_arr(buyArr);
            printf("已添加成功!");
            
        }
    }
}
void delebuyer()                     //删除买家
{
    int flag = 0;
    for (int i=1; i<=3; i++)
    {
        printf("请您输入您要删除的买家用户名:\n");
        char ddna[LENTH];
        scanf("%s",ddna);
        printf("请输入您要删除的买家用户密码:\n");
        int ddcode;
        scanf("%d",&ddcode);
        for (int j=0; j<=50; j++)
        {
            if (!strcmp(buyArr[j].bname,ddna)&&buyArr[j].bcode==ddcode)
            {
                for (int k=1; k<=3; k++)
                {
                    
                    
                    buyArr[j].bnumber=0;
                    strcpy(buyArr[j].bname,0);
                    buyArr[j].bcode=0;
                    buyArr[j].connect=0;
                    strcpy(buyArr[j].buymanaddress,0);
                    buyman_arr(buyArr);
                    flag=1;
                    
                }
            }else{
                flag=0;
            }
        }
        if (flag==0) {
            printf("输入错误，您还有%d次机会!\n",3-i);
        }
        
    }
}
void deleseller()
{
    int flag = 0;
    for (int i=1; i<=3; i++)
    {
        printf("请输入您要删除的卖家用户名:\n");
        char ddse[20];
        scanf("%s",ddse);
        printf("请输入您要删除的卖家用户密码:\n");
        int ddco;
        scanf("%d",&ddco);
        for (int j=0; j<=50; j++)
        {
            if (!strcmp(sellArr[j].uname,ddse)&&sellArr[j].ucode==ddco)
            {
                
                for (int k=1; k<=3; k++)
                {
                    sellArr[j].shopid=0;
                    strcpy(sellArr[j].uname,"");
                    sellArr[j].ucode=0;
                    strcpy(sellArr[j].shopname,"");
                    strcpy(sellArr[j].shopaddress, "");
                    sellArr[j].sort.sortnumber=0;
                    flag=1;
                    sellman_arr(sellArr);
                    return;
                    
                }
            }
            else
                flag=0;
            
        }
        if (flag==0) {
            printf("输入错误，您还有%d次机会!\n",3-i);
        }
    }
    
}
void modifymanagerinfo()//修改管理员个人信
{
    int flag=0;
    for (int j=1; j<=3; j++)
    {
        printf("请输入您的用户名:\n");
        char mname[20];
        scanf("%s",mname);
        for (int i=0; i<=50; i++)
        {
            if (!strcmp(man[i].managername,mname))        //管理员的结构体定义
            {
                for (int k=1; k<=3; k++)
                {
                    printf("请输入您的用户密码:\n");
                    int mcode;
                    scanf("%d",&mcode);
                    if (man[i].managercode)
                    {
                        printf("请您输入新的用户名:\n");
                        char nmname[LENTH];
                        scanf("%s",nmname);
                        printf("请您输入新的用户密码:\n");
                        int nmcode;
                        scanf("%d",&nmcode);
                        strcpy(man[i].managername,nmname);
                        man[i].managercode=nmcode;
                        printf("您已修改成功!\n");
                        flag=1;
                        return;
                        
                    }else if (!flag){
                        printf("输入用户密码不正确\n");
                        continue;
                    }
                }
            }
        }if(!flag)
        {
            printf("用户名输入错误");
            continue;
        }
    }
    
}
void modifySellerinfo()
{
    int flag=0;
    int f1=0;
    do{  int c;
        printf("请输入您的商店编号:");
        scanf("%d",&c);
        for(int i=0;i<=50;i++)
        {
            if(c==sellArr[i].shopid)
            {
                flag=1;
                do{
                    printf("请输入您的用户名:\n");
                    char mna[LENTH];
                    scanf("%s",mna);
                    for(int i=0;i<=50;i++)
                    {
                        if(!strcmp(sellArr[i].uname,mna))
                        {
                            f1=1;
                            do{
                                printf("请输入您的用户密码:\n");
                                int dd;
                                scanf("%d",&dd);
                                if(dd==sellArr[i].ucode)
                                {
                                    do{
                                        printf("请您选择您要修改的信息内容：\n\n");
                                        printf("\t\t\t1. 修改卖家用户名\n");
                                        printf("\t\t\t2. 修改卖家用户密码\n");
                                        printf("\t\t\t3. 修改卖家商店名称\n");
                                        printf("\t\t\t4. 修改卖家商店种类\n");
                                        printf("\t\t\t5. 修改卖家商店地址\n");
                                        printf("\n\n");
                                        printf("请输入数字进行选择或按0返回上级菜单:");
                                        int d;
                                        scanf("%d",&d);
                                        switch(d)
                                        {
                                            case(1):
                                                modifysellername(i);
                                                break;
                                            case(2):
                                                modifysellercode(i);
                                                break;
                                            case(3):
                                                modifystorename(i);
                                                break;
                                            case(4):
                                                modifystorekind(i);
                                                break;
                                            case 5:
                                                modifystoreaddress(i);
                                                break;
                                            case 0:
                                                return;
                                                break;
                                            default:
                                                break;
                                        }
                                        continue;
                                    }while(1);
                                }
                                else
                                    printf("密码输入错误\n");}while(1);
                        }
                        else
                        {
                            f1=0;
                        }
                    }
                    if (f1==0) {
                        printf("用户名输入错误\n");
                        continue;
                        
                    }
                }while(1);
                
                
            }
            else
                flag=0;
        }
        if (flag==0) {
            printf("商店编号输入错误\n");
            continue;
        }
        
    }while(1);
}
void modifysellername(int i)
{
    printf("请输入您的新用户名:\n");
    char nna[LENTH];
    scanf("%s",nna);
    strcpy(sellArr[i].uname,nna);
    sellman_arr(sellArr);
    printf("修改成功！\n");
    printf("%s\n",sellArr[i].uname);
    printf("请按0返回上级菜单:\n");
    int f;
    scanf("%d",&f);
    if(f==0)
    {
        return;
    }
}
void modifysellercode(int i)
{
    printf("请输入您的新密码");
    int ee;
    scanf("%d",&ee);
    sellArr[i].ucode=ee;
    sellman_arr(sellArr);
    printf("修改成功！\n");
    printf("%d\n",sellArr[i].ucode);
    printf("请按0返回上级菜单:\n");
    int f;
    scanf("%d",&f);
    if(f==0)
    {
        return;
    }
}
void modifystorename(int i)
{
    printf("请您输入新的商店名称:\n");
    char name[20];
    scanf("%s",name);
    strcpy(sellArr[i].shopname,name);
    sellman_arr(sellArr);
    printf("修改成功！\n");
    // printf("%d\n",sellArr[i].ucode);
    printf("请按0返回上级菜单:\n");
    int f;
    scanf("%d",&f);
    if(f==0)
    {
        return;
    }
}
void modifystorekind(int i)
{
    printf("请输入您要修改的商铺种类:\n");
    int sort;
    scanf("%d",&sort);
    sellman_arr(sellArr);
    printf("修改成功！\n");
    printf("%d  %s\n",sortArr[sort-1].sortnumber,sortArr[sort-1].sortname);
    printf("请按0返回上级菜单:\n");
    int f;
    scanf("%d",&f);
    if(f==0)
    {
        return;
    }
}
void modifystoreaddress(int i)
{
    printf("请输入您要修改的商铺地址:\n");
    char address[20];
    scanf("%s",address);
    strcpy(sellArr[i].shopaddress,address);
    sellman_arr(sellArr);
    printf("修改成功！\n");
    printf("%s\n",sellArr[i].shopaddress);
    printf("请按0返回上级菜单:\n");
    int f;
    scanf("%d",&f);
    if(f==0)
    {
        return;
    }
}
void active()          //制定
{
    struct Buyman temp;
    for (int i=0; i<LENTH; i++) {
        for (int j=0; j<LENTH; j++) {
            if (strcmp(dingArr[i].dbuyername,buyArr[j].buymanname)==0) {
                buyArr[j].count = dingArr[i].shijiprice/10;
                            }
        }
        
    }buyman_arr(buyArr);

    for (int i=0; i<LENTH; i++)
    {
        for (int j=0; j<LENTH-i; j++)         //
        {
            if (strcmp(buyArr[i].buymanname,"")) {
                continue;
            }
            else if (buyArr[j].count<buyArr[j+1].count) {
                temp=buyArr[j];
                buyArr[j]=buyArr[j+1];
                buyArr[j+1]=temp;
            }
        }
    }
    for (int i=0; i<=LENTH; i++) {
        if (strcmp(buyArr[i].buymanname,"")) {
            continue;
        }
        printf("%s,%d\n",buyArr[i].buymanname,buyArr[i].count);
        
    }
    printf("%s获得精美礼品一份！\n",buyArr[0].buymanname);
    return;
    
}

void dish_arr( struct Dish arr[LENTH][LENTH])
{
    FILE *fp;   //文件指针变量
    int ret;    //文件写数据的结果，写成功返回写 count 个数 ，失败返回 0
    fp = fopen("/Users/zhongruanmini029/Desktop/dish","w");  //以 w 写的形式打开 fname 文件
    if(fp == NULL){
        printf("%s文件不存在！\n","/Users/zhongruanmini029/Desktop/dish");
        return ;
    }
    //int i;
    //for(i = 0; i < len; i++){
    ret = fwrite(arr,sizeof(struct Buyman),20,fp);
    //if()break;
    // }
    fclose(fp);
    //if(ret > 0){
    printf("数据保存成功！\n");
    /* }else{
     printf("数据保存失败！\n");
     }*/
    
}


void buyman_arr(struct Buyman * arr)
{
    FILE *fp2;   //文件指针变量
    int ret;    //文件写数据的结果，写成功返回写 count 个数 ，失败返回 0
    fp2 = fopen("/Users/zhongruanmini029/Desktop/buyman","w");  //以 w 写的形式打开 fname 文件
    if(fp2 == NULL){
        printf("%s文件不存在！\n","/Users/zhongruanmini029/Desktop/buyman");
        return ;
    }
    //int i;
    //for(i = 0; i < len; i++){
    ret = fwrite(arr,sizeof(struct Buyman),20,fp2);
    //if()break;
    // }
    fclose(fp2);
    //if(ret > 0){
    printf("数据保存成功！\n");
    /* }else{
     printf("数据保存失败！\n");
     }*/
}
void sellman_arr(struct Sellman * arr)
{
    FILE *fp3;   //文件指针变量
    int ret;    //文件写数据的结果，写成功返回写 count 个数 ，失败返回 0
    fp3 = fopen("/Users/zhongruanmini029/Desktop/sellman","w");  //以 w 写的形式打开 fname 文件
    if(fp3 == NULL){
        printf("%s文件不存在！\n","/Users/zhongruanmini029/Desktop/sellman");
        return ;
    }
    //int i;
    //for(i = 0; i < len; i++){
    fwrite(arr,sizeof(struct Sellman),20,fp3);
    //if()break;
    // }
    fclose(fp3);
    //if(ret > 0){
    printf("数据保存成功！\n");
    /*}else{
     printf("数据保存失败！\n");
     }*/
    
}
void dingdan_arr(struct Dingdan * arr)
{
    FILE *fp4;   //文件指针变量
    //文件写数据的结果，写成功返回写 count 个数 ，失败返回 0
    fp4 = fopen("/Users/zhongruanmini029/Desktop/dingdan","w");  //以 w 写的形式打开 fname 文件
    if(fp4 == NULL){
        printf("%s文件不存在！\n","/Users/zhongruanmini029/Desktop/dingdan");
        return ;
    }
    //int i;
    //for(i = 0; i < len; i++){
    fwrite(arr,sizeof(struct Dingdan),20,fp4);
    //if()break;
    // }
    fclose(fp4);
    /* if(ret > 0){*/
    printf("数据保存成功！\n");
    /*}else{
     printf("数据保存失败！\n");
     }*/
    
}
void manager_arr(struct Manager * arr)
{
    FILE *fp5;   //文件指针变量
    int ret;    //文件写数据的结果，写成功返回写 count 个数 ，失败返回 0
    fp5 = fopen("/Users/zhongruanmini029/Desktop/manager","w");  //以 w 写的形式打开 fname 文件
    if(fp5 == NULL){
        printf("%s文件不存在！\n","/Users/zhongruanmini029/Desktop/manager");
        return ;
    }
    //int i;
    //for(i = 0; i < len; i++){
    ret = fwrite(arr,sizeof(struct Manager),20,fp5);
    //if()break;
    // }
    fclose(fp5);
    // if(ret > 0){
    printf("数据保存成功！\n");
    /* }else{
     printf("数据保存失败！\n");
     }*/
    
}
int loaddingdan_arr(char *fname, struct Dingdan * arr)
{
    FILE *fp;
    int ret;
    int i;
    fp = fopen(fname,"r");
    if(fp == NULL){
        printf("%s文件不存在！\n",fname);
        return 0;
    }
    for(i = 0; ; i++){
        ret = fread(arr+i,sizeof(struct Dingdan),1,fp);
        if (ret == 0) {
            break;
        }
    }
    printf("数据读取成功！\n");
    fclose(fp);
    return i;
}
int loadmanager_arr(char *fname, struct Manager * arr)
{
    FILE *fp;
    int ret;
    int i;
    fp = fopen(fname,"r");
    if(fp == NULL){
        printf("%s文件不存在！\n",fname);
        return 0;
    }
    for(i = 0; ; i++){
        ret = fread(arr+i,sizeof(struct Manager),1,fp);
        if (ret == 0) {
            break;
        }
    }
    printf("数据读取成功！\n");
    fclose(fp);
    return i;
}int loaddish_arr(char *fname, struct Dish arr[LENTH][LENTH])
{
    FILE *fp;
    int ret;
    int i;
    fp = fopen(fname,"r");
    if(fp == NULL){
        printf("%s文件不存在！\n",fname);
        return 0;
    }
    for(i = 0; ; i++){
        ret = fread(arr+i,sizeof(struct Dish),1,fp);
        if (ret == 0) {
            break;
        }
    }
    printf("数据读取成功！\n");
    fclose(fp);
    return i;
}
int loadsellman_arr(char *fname, struct Sellman * arr)
{
    FILE *fp;
    int ret;
    int i;
    fp = fopen(fname,"r");
    if(fp == NULL){
        printf("%s文件不存在！\n",fname);
        return 0;
    }
    for(i = 0; ; i++){
        ret = fread(arr+i,sizeof(struct Sellman),1,fp);
        if (ret == 0) {
            break;
        }
    }
    printf("数据读取成功！\n");
    fclose(fp);
    return i;
}
int loadbuyman_arr(char *fname, struct Buyman * arr)
{
    FILE *fp;
    int ret;
    int i;
    fp = fopen(fname,"r");
    if(fp == NULL){
        printf("%s文件不存在！\n",fname);
        return 0;
    }
    for(i = 0; ; i++){
        ret = fread(arr+i,sizeof(struct Buyman),1,fp);
        if (ret == 0) {
            break;
        }
    }
    printf("数据读取成功！\n");
    fclose(fp);
    return i;
}