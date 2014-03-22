
Jobshop:: Jobshop()
{
  numMachine = 6;
  numJob = 6;
  numOpe = 36;
  
  setDefaultOperation(numMachine+1,numJob+1);
  arrope[1][1] = Operation(1, 1, 3, 1);
  arrope[1][2] = Operation(2, 1, 2, 8);
  arrope[1][3] = Operation(3, 1, 3, 5);
  arrope[1][4] = Operation(4, 1, 2, 5);
  arrope[1][5] = Operation(5, 1, 3, 9);
  arrope[1][6] = Operation(6, 1, 2, 3);
  
  arrope[2][1] = Operation(1, 2, 1, 3);
  arrope[2][2] = Operation(2, 2, 3, 5);
  arrope[2][3] = Operation(3, 2, 4, 3); 
  arrope[2][4] = Operation(4, 2, 1, 5);
  arrope[2][5] = Operation(5, 2, 2, 3);
  arrope[2][6] = Operation(6, 2, 4, 3);
  
  arrope[3][1] = Operation(1, 3, 2, 6);
  arrope[3][2] = Operation(2, 3, 5, 10);
  arrope[3][3] = Operation(3, 3, 6, 8);
  arrope[3][4] = Operation(4, 3, 3, 5);
  arrope[3][5] = Operation(5, 3, 5, 5);
  arrope[3][6] = Operation(6, 3, 6, 9);      
  
  arrope[4][1] = Operation(1, 4, 4, 7);
  arrope[4][2] = Operation(2, 4, 6, 10);
  arrope[4][3] = Operation(3, 4, 1, 9);
  arrope[4][4] = Operation(4, 4, 4, 3);
  arrope[4][5] = Operation(5, 4, 6, 4);
  arrope[4][6] = Operation(6, 4, 1, 10); 
  
  arrope[5][1] = Operation(1, 5, 6, 3);
  arrope[5][2] = Operation(2, 5, 1, 10);
  arrope[5][3] = Operation(3, 5, 2, 1);
  arrope[5][4] = Operation(4, 5, 5, 8);
  arrope[5][5] = Operation(5, 5, 1, 3);
  arrope[5][6] = Operation(6, 5, 5, 4); 
  
  arrope[6][1] = Operation(1, 6, 5, 6);
  arrope[6][2] = Operation(2, 6, 4, 4);
  arrope[6][3] = Operation(3, 6, 5, 7);
  arrope[6][4] = Operation(4, 6, 6, 9);
  arrope[6][5] = Operation(5, 6, 4, 1);
  arrope[6][6] = Operation(6, 6, 3, 1); 
  
}
void Jobshop :: Initialize()
{
  
}
void Jobshop :: run()
{
  string tosave = "";
  for (int kk = 1; kk <= solanchay; kk++)
   {
     printf("Lan chay thu %d: \n",kk);
     thehe = 0;
     Gene bestBefore;
     InitPopulation();
     break;
   }
}
void Jobshop :: InitPopulation()
{
  string strTest = "";
  for (int k = 0; k < nPopulation; k++)
   {
      Operation **S;
      //Operation gt[(numMachine + 1)*(numJob + 1)];     
      GT(S);  
      /*
      int dem = 0;
      for (int i=0;i<numMachine+1;i++)
      for (int j=0;j<numJob+1;i++)
      {
        S[i][j]=gt[dem];
        dem++;      
      }
      //strTest = "S" + k + "={";
      for (int i = 1; i <= numMachine; i++)
        for (int j = 1; j <= numJob; j++)
          //if (S[i][j] != NULL)
                {
                    // MessageBox.Show(S[i, j].c.ToString());
                    gene.Add((Operation)S[i, j]);
                    //strTest += S[i, j].id.ToString() + "-";
                }
       */         
      //break;    
   }        
}
void Jobshop :: GT(Operation **S)
{
     S = new Operation *[numMachine + 1];
     for (int i=0; i< numMachine + 1 ; i++)
       S[i]=new Operation [numJob + 1];
       
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
      
     for (int k = 0; k < numOpe; k++)
      {
              
           Operation opeMinEc = findOpeMinEC(G);
           int machineIndex = opeMinEc.machineId;
           List<Operation> GM;  
           
           // Buoc 2
           for (int i = 0; i < G.Count; i++)
            if (G.ptu(i).machineId == machineIndex)
              GM.Add(G.ptu(i));
             
           // Buoc 3
           List<Operation> CM;//tap tranh chap
           for (int i = 0; i < GM.Count; i++)
            if (GM.ptu(i).ES < opeMinEc.EC) CM.Add(GM.ptu(i));
            
           // Buoc 4 --- luu y thu lai voi ramdomize()
           int idOpeChooser = Random(0,CM.Count);
           Operation opeChooser = CM.ptu(idOpeChooser);
                      
           // Buoc 5
           int J = machineIndex;
           int I = numOpeCom(PM, J) + 1;
           
           S[J][I] = opeChooser; // = (Operation)opeChooser.Clone();
           
           //PM[J].Add(S[J][I]);//PM[J].Add(S[J][I]);
           
           
           opeChooser.s = opeChooser.ES; //MessageBox.Show(S[J,I].s.ToString());
           opeChooser.c = opeChooser.EC; //MessageBox.Show(opeChooser.c.ToString());
           S[J][I].s = opeChooser.s;
           S[J][I].c = opeChooser.c; 
           //Buoc 6
           //foreach (Operation ope in GM)
           
           for (int i=0; i< GM.Count;i++)
            if (SS_Operation(GM.ptu(i),opeChooser)== false)
              {
               GM.Ptu(i)->ES = Max(GM.ptu(i).ES, opeChooser.EC);
               GM.Ptu(i)->EC = GM.ptu(i).ES + GM.ptu(i).pt;
              }
              
           // Buoc7 : da loai bot viec thay doi opeNext
                    
           Operation *OpeNext;
           Operation  opeNext;
           findOpeNext1(opeChooser,OpeNext);
           /*
           opeNext = findOpeNext(opeChooser);
           
           if (OpeNext != NULL)
            {
                      
              G.Add(opeNext);
              
              Operation opeResult = findOpeBothMachine(PM, opeNext);//thao tac da duoc lap lich cung may gan no nhat
              opeNext.ES = Max(opeChooser.EC, opeResult.EC);
              opeNext.EC = opeNext.ES + opeNext.pt;
              
            }
           //ObjRemove(&G,opeChooser);             
           */    
      }
      
      /*
      int dem=0;
      for (int i=0;i<(numMachine+1);i++)
         for (int j=0;j<(numJob+1);j++)
          {
            gt[dem]=S[i][j];
            dem++;
          }                
     */ 
     /*
     for (int i=1;i<=(numMachine+1);i++)
         for (int j=1;j<=(numJob+1);j++)
           printf("%d\n ",S[i][j].machineId);
     */      
}
void Jobshop :: ObjRemove(List<Operation> *G, Operation ope)
{
  Phantu<Operation> *p,*p1,*p2,*frist,*last;
  frist=G->frist;
  last=G->last;
  p = frist;
  //int n=0;
  while  ((p!= NULL))
   {
     if (SS_Operation(p->info,ope)== true)
     {    
         if (p==last)
         { 
              p->prev;
              last->next=NULL;
              delete(p);
         }
         else if (p==frist)
         {
              frist=p->next;
              frist->prev=NULL;
              delete(p);
         }
         else
         {
              p1=p->prev;
              p2=p->next;
              p1->next=p2;
              p2->prev=p1;
              delete(p);
         }   
         break;
     }     
     p=p->next;
 
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
     if ((arrope[ope.jobId][i].id == ope.id + 1) && ope.machineId != 0)
     opeNext = arrope[ope.jobId][i];//(Operation)arrope[ope.jobId, i].Clone();
    }
   return opeNext;
}    
void Jobshop :: findOpeNext1(Operation ope,Operation *OpeNext)
{
  for (int i = 1; i <= numMachine; i++)
    {
     if ((arrope[ope.jobId][i].id == ope.id + 1) && ope.machineId != 0)
     *OpeNext = arrope[ope.jobId][i];//(Operation)arrope[ope.jobId, i].Clone();
    }
   //return *opeNext;
}
bool Jobshop :: SS_Operation(Operation A,Operation B)
{
  if(A.machineId == B.machineId && A.jobId == B.jobId && A.id == B.id && A.pt == B.pt && A.ES==B.ES && A.EC == B.EC && A.s == B.s && A.c == B.c)
       return true;
  else return false;   
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
