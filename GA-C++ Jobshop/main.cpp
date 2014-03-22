#include <cstdlib>
#include <iostream>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "DS.h"
#include "BaseObject.h"
#include "Operation.h"
#include "Gene.h"

using namespace std;
string toStr(int number)
{
    if (number == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}
class Jobshop
{
  int M;
  int numJob; 
  int numMachine;
  int numOpe;
  int thehe;
  float F_Total;     
  List<Gene> population;
  public: Operation arrope[7][7];
  public: int nGeneration;
  public: float pCrossover ;
  public: float pMutation ;
  public: int nPopulation;
  public: int solanchay;
  public: Gene currentBest;
  public: Gene gTest;
  
  Jobshop();
  public: void run();
      public: void Initialize();
         private: void setDefaultOperation(int m, int j);
      private: void InitPopulation();
         public: void GT(Operation **S);
            private: Operation findOpeMinEC(List<Operation> G);
            private: int numOpeCom(List<Operation> PM[], int machineIndex);
            private: bool findOpeNext1(Operation ope);
            private: Operation findOpeBothMachine(List<Operation> PM[], Operation opeNext);
            private: Operation findOpeNext(Operation ope);
            private: void view_gene(Gene Gene)
             {
                for (int j = 1; j <= numMachine; j++)
                    {
                        cout << "May " << j << " :";
                        for (int i=0; i<Gene.Count; i++)
                        {
                            if (Gene.ptu(i).machineId == j)
                            {
                                cout <<" CV " << Gene.ptu(i).jobId << "(" << Gene.ptu(i).pt << "," << Gene.ptu(i).s << "," << Gene.ptu(i).c<< "),";
                            }
                        }
                        cout << endl;
                    }     
             }        
            private: void test(List<Operation> G, string s)
             {
                     cout << s; 
                     for (int i=0; i< G.Count;i++)   
                      printf("%d(%d %d) ",G.ptu(i).id,G.ptu(i).ES,G.ptu(i).EC);      
                     printf("\n");
             }
      public: void tinhM();       
      public : void selectMutation();
         public : List<Gene> Select();
            public : void tinhFtotal();
            public: float tinhMakespan(Gene g); 
            public: void tinhQ();
         public: void Mutation(Gene g);
            public: int getMachine(Operation o);
            public: bool updateGene(Gene g);  
              public: bool checkGene(Gene g); 
              public: Operation findOpeInJob1(Gene g, Operation ope);
              public: Operation findOpeInMach1(Gene g, Operation ope);
              public: Operation findOpeInJob(Gene g, Operation ope);
              public: Operation findOpeInMach(Gene g, Operation ope);
              public: bool S_findOpeInJob1(Gene g, Operation ope);
              public: bool S_findOpeInMach1(Gene g, Operation ope);
              public: bool S_findOpeInJob(Gene g, Operation ope);
              public: bool S_findOpeInMach(Gene g, Operation ope);
            public: bool kiemtratrunggene(Gene g);
               public: string strGene(Gene g);
      public : void selectCrossOver();
           public: Gene CrossOver(Gene g1, Gene g2);  
      public : List<Gene> Bubble();       
         
}; 

int main(int argc, char *argv[])
{
      randomize();
      Jobshop js;
      printf("BAI TOAN LAP LICH JOB SHOP\n");
      /*
          printf("Nhap so the he: "); scanf("%d",&js.nGeneration); // so the he
          printf("Nhap xac suat phep lai: "); scanf("%f",&js.pCrossover); // xac suat phep lai
          printf("Nhap xac suat dot bien: "); scanf("%f",&js.pMutation); // xac suat dot bien
          printf("Nhap so ca the khoi tao: ");scanf("%d",&js.nPopulation); // so ca the khoi tao
          printf("Nhap so lan chay: "); scanf("%d",&js.solanchay); // so lan chay
      */
      js.nGeneration=200; // so the he
      js.pCrossover=0.8; // xac suat phep lai
      js.pMutation=0.1; // xac suat dot bien
      js.nPopulation=100; // so ca the khoi tao
      js.solanchay=10; // so lan chay
      //js.Initialize();
      js.run();
    system("PAUSE");
    return EXIT_SUCCESS;
}


Jobshop:: Jobshop()
{
  numMachine = 6;
  numJob = 6;
  numOpe = 36;
  
  setDefaultOperation(numMachine+1,numJob+1);
  /*
  arrope[1][1] = Operation(1, 1, 1, 3);
  arrope[1][2] = Operation(2, 1, 2, 3);
  arrope[1][3] = Operation(3, 1, 3, 3);
  arrope[2][1] = Operation(1, 2, 4, 2);
  arrope[2][2] = Operation(3, 2, 5, 3);
  arrope[2][3] = Operation(2, 2, 6, 4);
  arrope[3][1] = Operation(2, 3, 7, 3);
  arrope[3][2] = Operation(1, 3, 8, 2);
  arrope[3][3] = Operation(3, 3, 9, 1);
  */
  
  arrope[1][1] = Operation(3, 1, 1, 1);
  arrope[1][2] = Operation(1, 1, 2, 3);
  arrope[1][3] = Operation(2, 1, 3, 6);
  arrope[1][4] = Operation(4, 1, 4, 7);
  arrope[1][5] = Operation(6, 1, 5, 3);
  arrope[1][6] = Operation(5, 1, 6, 6);
  
  arrope[2][1] = Operation(2, 2, 7, 8);
  arrope[2][2] = Operation(3, 2, 8, 5);
  arrope[2][3] = Operation(5, 2, 9, 10); 
  arrope[2][4] = Operation(6, 2, 10, 10);
  arrope[2][5] = Operation(1, 2, 11, 10);
  arrope[2][6] = Operation(4, 2, 12, 4);
  
  arrope[3][1] = Operation(3, 3, 13, 5);
  arrope[3][2] = Operation(4, 3, 14, 4);
  arrope[3][3] = Operation(6, 3, 15, 8);
  arrope[3][4] = Operation(1, 3, 16, 9);
  arrope[3][5] = Operation(2, 3, 17, 1);
  arrope[3][6] = Operation(5, 3, 18, 7);      
  
  arrope[4][1] = Operation(2, 4, 19, 5);
  arrope[4][2] = Operation(1, 4, 20, 5);
  arrope[4][3] = Operation(3, 4, 21, 5);
  arrope[4][4] = Operation(4, 4, 22, 3);
  arrope[4][5] = Operation(5, 4, 23, 8);
  arrope[4][6] = Operation(6, 4, 24, 9); 
  
  arrope[5][1] = Operation(3, 5, 25, 9);
  arrope[5][2] = Operation(2, 5, 26, 3);
  arrope[5][3] = Operation(5, 5, 27, 5);
  arrope[5][4] = Operation(6, 5, 28, 4);
  arrope[5][5] = Operation(1, 5, 29, 3);
  arrope[5][6] = Operation(4, 5, 30, 1); 
  
  arrope[6][1] = Operation(2, 6, 31, 3);
  arrope[6][2] = Operation(4, 6, 32, 3);
  arrope[6][3] = Operation(6, 6, 33, 9);
  arrope[6][4] = Operation(1, 6, 34, 10);
  arrope[6][5] = Operation(5, 6, 35, 4);
  arrope[6][6] = Operation(3, 6, 36, 1); 
  
}
void Jobshop :: Initialize()
{
  
}
void Jobshop :: run()
{
  //string tosave = "";
  for (int kk = 1; kk <= solanchay; kk++)
   {
     printf("Lan chay thu %d: \n",kk);
     thehe = 0;
     Gene bestBefore;
     InitPopulation();
     tinhM();
     float min = 0;
     
     for (int i = 0; i <= nGeneration; i++)
        {
            
            if (nGeneration > 0)
            {
                bestBefore = currentBest;
            }        
            selectMutation();
            selectCrossOver();
            population = Bubble();            
            int dem = 0;
            min =(float)M - population.ptu(0).getEval;
            //printf("%f\n",min);  
            currentBest = population.ptu(0);
            thehe++;            
        }
     cout << "Bai toan " << numMachine << " May - " << numJob << " Cong Viec \n";
     cout << "Ket qua toi uu : " << min << " Voi " << nPopulation << " Ca the sau : " << nGeneration << " The he \n";
     view_gene(population.ptu(0));              
     cout <<endl;
   }
}
List<Gene> Jobshop :: Bubble()
{
    float max;
    List<Gene> temp;
    max = population.ptu(0).getEval;
    for (int i = 0; i < population.Count - 1; i++)
    {
        for (int j = i + 1; j < population.Count; j++)
        {
            if (population.ptu(i).getEval < population.ptu(j).getEval)
            {
                Gene tg;
                tg = population.ptu(i);
                *population.Ptu(i) = population.ptu(j);
                *population.Ptu(j) = tg;
            }
        }
    }
   
    if (population.Count > nPopulation)
    {
        for (int i = 0; i < nPopulation; i++)
        {
            temp.Add(population.ptu(i));
            // temp.RemoveAt(i);
        }
        return temp;
    }
    else
    { //population = temp; 
        return population;
    }
}
void Jobshop :: selectCrossOver()
{
    List<Gene> listcross;
    int n = (int)pCrossover * numOpe;
    List<Gene> Temp;
    Temp = Select();
    //MessageBox.Show(Temp.Count.ToString());
    for (int i = 0; i < nPopulation; i++)
    {
      float rd = (float)Random(0,10)/10;  
      if (rd < pCrossover)
        {
            listcross.Add(Temp.ptu(i));
        }
    }
    if (listcross.Count % 2 != 0)
    {
        listcross.RemoveAt(listcross.Count - 1);
    }
    
    if (listcross.Count > 0)
    {
      for (int i = 0; i < listcross.Count - 1; i += 2)
        {
          Gene g;
          do
          {
            g = CrossOver(listcross.ptu(i), listcross.ptu(i+1));
          } while (updateGene(g) == false);
          
          if (kiemtratrunggene(g) == false)
            {
                tinhMakespan(g);
                population.Add(g);
            }
         
        }
    }
    
} 
Gene Jobshop :: CrossOver(Gene g1, Gene g2)
{
  Gene child;   
  Operation S[numMachine + 1][numJob + 1];
  Operation S1[numMachine + 1][numJob + 1];
  Operation S2[numMachine + 1][numJob + 1];
  {
    int k = 0;
    for (int i = 1; i <= numMachine; i++)
      for (int j = 1; j <= numJob; j++)
       {
         S1[i][j] = g1.ptu(k);
         k++;
       }
  }
  {
    int k = 0;
    for (int i = 1; i <= numMachine; i++)
      for (int j = 1; j <= numJob; j++)
        {
           S2[i][j] = g2.ptu(k);
           k++;
        }
  }
  List<Operation> G;
  List<Operation> C;
  List<Operation> PM[numMachine + 1];
  //buoc 1 khoi tao tap G la cac thao tac tren cot dau tien
  for (int i = 1; i <= numJob; i++)
    {
        Operation ope = (Operation)arrope[i][1];//(Operation)arrope[i, 1].Clone();
        ope.ES = 0;
        ope.EC = ope.pt;
        G.Add(ope);
    }
  for (int k = 0; k < numOpe; k++)
    {
        Operation opeMinEc = findOpeMinEC(G);
        int machineIndex = opeMinEc.machineId;
        List<Operation> GM;
        //tinh tap GM o buoc 2
        for (int i = 0; i < G.Count; i++)
        {
            if (G.ptu(i).machineId == machineIndex)
            {
                GM.Add(G.ptu(i));
            }
        }   
        //buoc 3
        List<Operation> CM;//tap tranh chap
        for (int i = 0; i < GM.Count; i++)
        {
            if (GM.ptu(i).ES < opeMinEc.EC) CM.Add(GM.ptu(i));
        }
        //buoc 4
        Operation opeChooser;
        int num = Random(0,2);
        int Lmin = pow(2,8)-1;
        if (num == 0)
        {
            for (int kk = 0; kk < CM.Count; kk++)
            {
                int i = CM.ptu(kk).jobId;
                int l = pow(2,8)-1;
                for (int j = 1; j <= numJob; j++)
                    if (S1[machineIndex][j].jobId == i) 
                    {
                        l = j;
                        break;
                    }
                if (l < Lmin) Lmin = l;
            }
            int r = S1[machineIndex][Lmin].jobId;
            
            for (int i = 0; i < CM.Count; i++)
            {
                Operation x = CM.ptu(i);
                if (x.jobId == r) opeChooser = x;
            }
        }
        else
        {
            for (int kk = 0; kk < CM.Count; kk++)
            {
                int i = CM.ptu(kk).jobId;
                int l = pow(2,8)-1;
                for (int j = 1; j <= numJob; j++)
                    if (S2[machineIndex][ j].jobId == i)
                    {
                        l = j;
                        break;
                    }
                if (l < Lmin) Lmin = l;
            }
            int r = S2[machineIndex][Lmin].jobId;
            //opeChooser = (Operation)arrope[r, machineIndex].Clone();
            for (int i = 0; i < CM.Count; i++)
            {
                Operation x = CM.ptu(i);
                if (x.jobId == r) opeChooser = x;
            }
        }
       // Buoc 5
        int J = machineIndex;
        int I = numOpeCom(PM, J) + 1;
        S[J][I] = opeChooser;//(Operation)opeChooser.Clone();
        PM[J].Add(S[J][ I]);
        opeChooser.s = opeChooser.ES; //MessageBox.Show(S[J,I].s.ToString());
        opeChooser.c = opeChooser.EC; //MessageBox.Show(opeChooser.c.ToString());
        S[J][ I].s = opeChooser.s;
        S[J][ I].c = opeChooser.c; 
        
        //Buoc 6
        //foreach (Operation ope in GM)
        for (int i=0; i< GM.Count;i++)
         if (GM.ptu(i).id != opeChooser.id)
           {
            GM.Ptu(i)->ES = Max(GM.ptu(i).ES, opeChooser.EC);
            GM.Ptu(i)->EC = GM.ptu(i).ES + GM.ptu(i).pt;
           }  
        // Buoc7 : da loai bot viec thay doi opeNext
        Operation  opeNext;
        opeNext = findOpeNext(opeChooser);
        if (findOpeNext1(opeChooser)==true)
         {
           Operation opeResult = findOpeBothMachine(PM, opeNext);//thao tac da duoc lap lich cung may gan no nhat
           opeNext.ES = Max(opeChooser.EC, opeResult.EC);
           opeNext.EC = opeNext.ES + opeNext.pt;                                
           G.Add(opeNext);
         }
        G.Remove(opeChooser.id);        
    }       
    for (int i = 1; i <= numMachine; i++)
      for (int j = 1; j <= numJob; j++)
         child.Add(S[i][j]);
    return child;
}
void Jobshop :: selectMutation()
{
   List<Gene> listMutation;
   int n = (int)pMutation * numOpe;
   List<Gene> Temp;
   Temp = Select();
   
   for (int i = 0; i < nPopulation; i++)
    {
      float rd = (float)Random(0,10)/10;
      if (rd < pMutation) listMutation.Add(Temp.ptu(i));
    }  
   if (listMutation.Count > 0)
    for (int i = 0; i < listMutation.Count ; i ++)
      Mutation(listMutation.ptu(i));  
      
}
void Jobshop :: Mutation(Gene g)
 {
   Gene geneResult;
   for(int i=0;i<g.Count;i++)
    {
      Operation ope1 = (Operation)g.ptu(i);//nguyen goc phai = (Operation)g.ptu(i).Clone();
      geneResult.Add(ope1);
    }
   int p1, p2;
   do
   {
      p1 = Random(0, geneResult.Count);
      p2 = Random(0, geneResult.Count);
                        //MessageBox.Show("Do dai gene : "+g.Count.ToString());
                        //MessageBox.Show(this.getMachine(g[p1]).ToString());
                        //MessageBox.Show(this.getMachine(g[p2]).ToString());
      if (getMachine(geneResult.ptu(p1)) == getMachine(geneResult.ptu(p2)) && (p1 != p2))
        {
          Operation temp;
          temp = geneResult.ptu(p2);
          geneResult.ptu(p2) = geneResult.ptu(p1);
          geneResult.ptu(p1) = temp;
                        //    MessageBox.Show(p2.ToString() + " " + p1.ToString());
        }
   } while (getMachine(geneResult.ptu(p1)) != getMachine(geneResult.ptu(p2)) || (p1 == p2));
                    //   MessageBox.Show("tetete");
                    //} while (this.updateGene(geneResult) == false);
   if (updateGene(geneResult) == true && kiemtratrunggene(geneResult)==false)
     {
      tinhMakespan(geneResult);
      population.Add(geneResult);
                      // MessageBox.Show("A");
     }
}
bool Jobshop :: kiemtratrunggene(Gene g)
{
   bool rs = false;
   //foreach (Gene ge in population)
   for(int i=0;i<population.Count;i++)
    {
      if (strGene(g) == strGene(population.ptu(i)))
        {
          rs = true;
          break;
        }
    }
   return rs;
}
string Jobshop :: strGene(Gene g)
{
    string str = "";
    for (int i = 0; i < g.Count; i++)
    {
        str += toStr(g.ptu(i).id) + "-";
    }
    return str;
}
bool Jobshop :: updateGene(Gene g)
{
for(int i=0; i<g.Count; i++)
{
 g.Ptu(i)->s = 0;
 g.Ptu(i)->c = 0;
 g.Ptu(i)->state = false;
}          
float btime=0;
bool exit = true ;
int count=0;       
while (checkGene(g)==false)
{
 count=0;            
 for(int i=0; i<g.Count; i++)            
                          //foreach (Operation ope in g)  
  {
    if (g.ptu(i).state == false)
      {
        if ( (S_findOpeInJob(g,g.ptu(i)) == false) && (S_findOpeInMach(g,g.ptu(i)) == false) )
          {
            g.Ptu(i)->s = 0;
            g.Ptu(i)->c = g.ptu(i).pt;
            g.Ptu(i)->state = true;
            count = 1;
          }
        else if (S_findOpeInJob(g, g.ptu(i)) == false && S_findOpeInMach1(g, g.ptu(i)) != false)
          {
            Operation o;
            o = findOpeInMach1(g, g.ptu(i));
            g.Ptu(i)->s = o.c;
            g.Ptu(i)->c = g.ptu(i).s + g.ptu(i).pt;
            g.Ptu(i)->state = true;
            count = 1;
          }   
        else if (S_findOpeInJob1(g, g.ptu(i)) != false && S_findOpeInMach(g, g.ptu(i)) == false)
          {
            Operation o;
            o = findOpeInJob1(g, g.ptu(i));
            g.Ptu(i)->s = o.c;
            g.Ptu(i)->c = g.ptu(i).s + g.ptu(i).pt;
            g.Ptu(i)->state = true;
            count = 1;
          }    
        else if (S_findOpeInMach1(g, g.ptu(i)) != false && S_findOpeInJob1(g, g.ptu(i)) != false)
          {
            Operation o;
            Operation o1;
            o = findOpeInMach1(g, g.ptu(i));
            o1 = findOpeInJob1(g, g.ptu(i));
            btime = Max(o.c, o1.c);
            g.Ptu(i)->s = (int)btime;
            g.Ptu(i)->c = g.ptu(i).s + g.ptu(i).pt;
            g.Ptu(i)->state = true;
            count = 1;
          }   
       }
   } 
 if (count == 0)
   {
     exit = false;
     break;
   }                         
}
return exit;
}   
// findOpeInJob findOpeInMach-------------------------------------------------------------------
Operation Jobshop :: findOpeInJob1(Gene g, Operation ope)
{
    Operation opeRe;
    for (int i = 0; i < g.Count; i++)
    {
        if (g.ptu(i).state==true && g.ptu(i).jobId == ope.jobId && g.ptu(i).id ==( ope.id - 1))
        {
            opeRe = g.ptu(i);
            break;
        }
    }
    return opeRe;
}
Operation Jobshop :: findOpeInMach1(Gene g, Operation ope)
{
    Operation opeRe;
    int k = 0;
    for (int i = 0; i < g.Count; i++)
    {
        if (g.ptu(i).id==ope.id)
        {
            k = i - 1;
            break;
        }
    }
    if (k >= 0)
    {
        if (g.ptu(k).state == true  && g.ptu(k).machineId == ope.machineId)
           opeRe = g.ptu(k);
    }
    return opeRe;
}
Operation Jobshop :: findOpeInJob(Gene g, Operation ope)
{
    Operation opeRe;
    for (int i = 0; i < g.Count; i++)
    {
        if (g.ptu(i).jobId == ope.jobId && g.ptu(i).id == (ope.id - 1))
        {
            opeRe = g.ptu(i);
            break;
        }
    }
    return opeRe;
}
Operation Jobshop :: findOpeInMach(Gene g, Operation ope)
{
    Operation opeRe;
    int k = 0;
    for (int i = 0; i < g.Count; i++)
    {
        if (g.ptu(i).id == ope.id)
        {
            k = i - 1;
            break;
        }
    }
    if (k >= 0)
    {
        if (g.ptu(k).machineId == ope.machineId)
            opeRe = g.ptu(k);
    }
    return opeRe;
} 
              
bool Jobshop :: S_findOpeInJob1(Gene g, Operation ope)
{
    bool opeRe = false;
    for (int i = 0; i < g.Count; i++)
    {
        if (g.ptu(i).state==true && g.ptu(i).jobId == ope.jobId && g.ptu(i).id ==( ope.id - 1))
        {
            opeRe = true;
            break;
        }
    }
    return opeRe;
}
bool Jobshop :: S_findOpeInMach1(Gene g, Operation ope)
{
    bool opeRe=false;
    int k = 0;
    for (int i = 0; i < g.Count; i++)
    {
        if (g.ptu(i).id==ope.id)
        {
            k = i - 1;
            break;
        }
    }
    if (k >= 0)
    {
        if (g.ptu(k).state == true  && g.ptu(k).machineId == ope.machineId)
           opeRe = true;
    }
    return opeRe;
}
bool Jobshop :: S_findOpeInJob(Gene g, Operation ope)
    {
        bool opeRe=false;
        for (int i = 0; i < g.Count; i++)
        {
            if (g.ptu(i).jobId == ope.jobId && g.ptu(i).id == (ope.id - 1))
            {
                opeRe = true;
                break;
            }
        }
        return opeRe;
    }
bool Jobshop :: S_findOpeInMach(Gene g, Operation ope)
    {
        bool opeRe=false;
        int k = 0;
        for (int i = 0; i < g.Count; i++)
        {
            if (g.ptu(i).id == ope.id)
            {
                k = i - 1;
                break;
            }
        }
        if (k >= 0)
        {
            if (g.ptu(k).machineId == ope.machineId)
                opeRe = true;
        }
        return opeRe;
    }    
// findOpeInJob findOpeInMach-------------------------------------------------------------------  
bool Jobshop :: checkGene(Gene g)
{
   bool rs=true;
   Operation ope1;// thua ... ???
   for(int i=0; i<g.Count; i++)
    if (g.ptu(i).state == false)
     {
       ope1=g.ptu(i); // thua ... ???
       rs = false;
       break;
     }
   return rs;
} 
int Jobshop :: getMachine(Operation o)
{
return o.machineId;
} 
List<Gene> Jobshop :: Select()
{
           
    Gene max = population.ptu(0);
    float GiaTri = max.getEval;
       
    for (int i = 0; i< population.Count; i++)    
     if (GiaTri < population.ptu(i).getEval)
        {
            max = population.ptu(i);
            GiaTri = max.getEval;
            
        }
    tinhFtotal();
    
    for (int i = 0;i < population.Count;i++)
    {
     population.Ptu(i)->getp=0;
     population.Ptu(i)->getp=(float)(population.Ptu(i)->getEval)/F_Total;
    }
    tinhQ();
    List<Gene> newPopulation;
    newPopulation.Add(max);
    for(int i=0;i< nPopulation - 1;i++)
     {
      float rd1 = (float)Random(0,10)/10; 
      if (population.ptu(0).getq >= rd1) newPopulation.Add(population.ptu(0));
      else
       {
         for(int j=1;j<population.Count;j++)
           if (population.ptu(j-1).getq < rd1 && rd1 <= population.ptu(j).getq)
            {
              newPopulation.Add(population.ptu(j));
              break;
            }
        }    
     }
   
   return newPopulation;  
}      
void Jobshop :: tinhQ()
 {
    int i = 0;
    //foreach (Gene g in population)
    for (int t=0; t< population.Count ; t++)
    {
        population.ptu(t).getq = 0;
        float tq = 0;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                tq = population.ptu(t).getp;
            }
            else if (j > 0)
            {
                tq = tq + population.ptu(j).getp;
            }
        }
        population.ptu(t).getq = tq;
        i += 1;
        
    }
 }
void Jobshop :: tinhFtotal()
{
   F_Total = 0;
   for (int i = 0;i < population.Count;i++)
    {
      F_Total = F_Total + tinhMakespan(population.ptu(i));
    }
}           
float Jobshop :: tinhMakespan(Gene g)
{
  float max = g.ptu(0).c;
  for (int i = 0; i < g.Count; i++)
    if (g.ptu(i).c > max)
     max = g.ptu(i).c;
  g.getEval = M - max;
  return g.getEval;
}

void Jobshop::tinhM()
{
    M = 0;
    M = (int)pow(2,15)-1/ nPopulation;
}
void Jobshop :: InitPopulation()
{
  
  for (int k = 0; k < nPopulation; k++)
   {
      Operation **S;
      
      S = new Operation *[numMachine + 1];
      for (int i=0; i< numMachine + 1 ; i++)
       S[i]=new Operation [numJob + 1];
       
      for (int i=0; i< numMachine + 1 ; i++)
       for (int j=0; j< numJob + 1 ; j++)
         S[i][j].id=0; 
      
      GT(S);
      
      Gene gene;
      for (int i = 1; i <= numMachine; i++)
        for (int j = 1; j <= numJob; j++)   
           if (S[i][j].id != 0)     gene.Add(S[i][j]);
      gene.isGT = true;
      //view_gene(gene);
      //printf("\n");
      population.Add(gene);   
   }        
 //printf("%d\n",population.Count);
}

void Jobshop :: GT(Operation **S)
{
     
          
    // Operation S[numMachine + 1][numJob + 1];  
     List<Operation> G;
     List<Operation> C;
     
     //List<Operation> *PM = new List<Operation>[numMachine + 1];
     List<Operation> PM[numMachine + 1];
     
     for (int i = 1; i <= numJob; i++)
      {
        Operation ope = arrope[i][1]; //(Operation)arrope[i, 1].Clone();
        //printf("%d\n ",ope.id); //test
        ope.ES = 0;
        ope.EC = ope.pt;
        G.Add(ope);  
      }
     
     for (int k = 0; k < numOpe ; k++)
      {
           //printf("numOpe = %d \n",k);   
                                  
           Operation opeMinEc = findOpeMinEC(G);
           int machineIndex = opeMinEc.machineId;
           List<Operation> GM;  
          
           // Buoc 2
           for (int i = 0; i < G.Count; i++)
            if (G.ptu(i).machineId == machineIndex)
              GM.Add(G.ptu(i));             
           //test (GM,"GM: ");
           // Buoc 3
           List<Operation> CM;//tap tranh chap
           for (int i = 0; i < GM.Count; i++)
            if (GM.ptu(i).ES < opeMinEc.EC) CM.Add(GM.ptu(i));
            
           //test (CM,"CM: ");
           // Buoc 4 --- luu y thu lai voi ramdomize()
       
           int idOpeChooser = Random(0,CM.Count);
           Operation opeChooser = CM.ptu(idOpeChooser);
                      
           // Buoc 5
           int J = machineIndex;
           int I = numOpeCom(PM, J) + 1;
           //printf("%d %d\n",J,I);
                     
           S[J][I] = opeChooser; // = (Operation)opeChooser.Clone();
                      
           PM[J].Add(S[J][I]);//PM[J].Add(S[J][I]);
           //test (PM[J],"PM: ");      
           
           opeChooser.s = opeChooser.ES; //MessageBox.Show(S[J,I].s.ToString());
           opeChooser.c = opeChooser.EC; //MessageBox.Show(opeChooser.c.ToString());
           S[J][I].s = opeChooser.s;
           S[J][I].c = opeChooser.c; 
          
           //Buoc 6
           //foreach (Operation ope in GM)
           for (int i=0; i< GM.Count;i++)
            if (GM.ptu(i).id != opeChooser.id)
              {
               GM.Ptu(i)->ES = Max(GM.ptu(i).ES, opeChooser.EC);
               GM.Ptu(i)->EC = GM.ptu(i).ES + GM.ptu(i).pt;
              }
           
           // Buoc7 : da loai bot viec thay doi opeNext
                
           Operation  opeNext;
           opeNext = findOpeNext(opeChooser);
           if (findOpeNext1(opeChooser)==true)
            {
              Operation opeResult = findOpeBothMachine(PM, opeNext);//thao tac da duoc lap lich cung may gan no nhat
              opeNext.ES = Max(opeChooser.EC, opeResult.EC);
              opeNext.EC = opeNext.ES + opeNext.pt;                                
              G.Add(opeNext);
            }
           
           //printf("opeChooser.id: %d\n",opeChooser.id);
           //if (findOpeNext1(opeChooser)==true) printf("opeNext: %d(%d %d)\n",opeNext.id,opeNext.ES,opeNext.EC);
           //printf("%d - ",G.Count);                 
           // test(G,"G: ");    
           G.Remove(opeChooser.id);
           //printf("\n"); 
                  
      }
          
}

Operation Jobshop :: findOpeBothMachine(List<Operation> PM[], Operation opeNext)
{
   Operation opeResult;
   if (PM[opeNext.machineId].Count != 0) opeResult = PM[opeNext.machineId].ptu(PM[opeNext.machineId].Count - 1);
   else
    {
      opeResult.EC = 0;
    }
   return opeResult;
} 
Operation Jobshop :: findOpeNext(Operation ope)
{
   Operation opeNext;
   for (int i = 1; i <= numMachine; i++)
    {
     if ((arrope[ope.jobId][i].id == ope.id + 1) && (ope.machineId != 0))
     opeNext = arrope[ope.jobId][i];//(Operation)arrope[ope.jobId, i].Clone();
    }
   return opeNext;
}    
bool Jobshop :: findOpeNext1(Operation ope)
{
  bool kq=false;   
  for (int i = 1; i <= numMachine; i++)
      if ((arrope[ope.jobId][i].id == ope.id + 1) && (ope.machineId != 0))
        kq= true;

  return kq;
}

int Jobshop :: numOpeCom(List<Operation> PM[], int machineIndex)
{
  int count = PM[machineIndex].Count;
  return count;
}
Operation Jobshop :: findOpeMinEC(List<Operation> G)
{
  Operation opeResult;
  if (G.Count > 0)
    {
       opeResult = G.ptu(0);
       for (int i = 0; i < G.Count; i++)
       if (G.ptu(i).EC < opeResult.EC) opeResult = G.ptu(i);
    }
  return opeResult;
}
void Jobshop:: setDefaultOperation(int m, int j)
{
 for (int i = 0; i < j; i++)
  for (int k = 0; k < m; k++)
        arrope[i][k].machineId = 0;
}
