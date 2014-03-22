class Operation : public BaseObject
{
 public :     
  int machineId; // chi so may
  int jobId;// chi so cong viec
  int id; // chi so ma hoa thao tac
  int pt; // thoi gian xu ly 
  int ES;// thoi gian bat dau som nhat
  int EC; // thoi gian ket thuc som nhat
  int s; // thoi gian bat dau
  int c; // thoi gian ket thuc
  float maxTMach;
  float maxTJob;
  bool state;
  Operation()
    {
     state = false;          
    }
  Operation(int _machineId,int _jobId,int _id,int _pt)
    {
      state = false;          
      machineId = _machineId;
      jobId = _jobId;
      id = _id;
      pt = _pt;
    }
  Operation clone()
   {
   }
};
