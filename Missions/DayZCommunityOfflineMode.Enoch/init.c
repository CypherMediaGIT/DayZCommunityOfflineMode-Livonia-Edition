#define DISABLE_PERSISTENCY

#include "$CurrentDir:Missions\\DayZCommunityOfflineMode.Enoch\\core\\BaseModuleInclude.c"

Mission CreateCustomMission(string path)
{	
    if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
        return new CommunityOfflineServer();

    return new CommunityOfflineClient();
}

void SpawnObject(string objectName, vector position, vector orientation)
{
    Object obj;
    obj = Object.Cast(GetGame().CreateObject(objectName, "0 0 0"));
    obj.SetPosition(position);
    obj.SetOrientation(orientation);
        //Force collision update
    vector roll = obj.GetOrientation();
    roll [ 2 ] = roll [ 2 ] - 1;
    obj.SetOrientation( roll );
    roll [ 2 ] = roll [ 2 ] + 1;
    obj.SetOrientation( roll );
 
    // Force update collisions
    if (obj.CanAffectPathgraph())
    {
        obj.SetAffectPathgraph(true, false);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
    }
}
void main()
{
	//Green Mtn




}