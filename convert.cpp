#include <iostream>
#include <STEPControl_Reader.hxx>
#include <TopoDS_Shape.hxx>
#include <StlAPI_Writer.hxx>
#include <StlAPI.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <string>
#include <iostream>
using namespace std;

int main (int argc, char *argv[]){
    //Read from STEP
    STEPControl_Reader reader;
    IFSelect_ReturnStatus stat = reader.ReadFile("sample_e.stp");

    Standard_Integer NbRoots = reader.NbRootsForTransfer();
    Standard_Integer NbTrans = reader.TransferRoots();
    TopoDS_Shape shape = reader.OneShape();
    BRepMesh_IncrementalMesh aMesh(shape, 10.0);

    //Write to STL
    StlAPI_Writer stlWriter = StlAPI_Writer();
    stlWriter.Write(shape, "conversion_e.stl");
    return 0;
}
