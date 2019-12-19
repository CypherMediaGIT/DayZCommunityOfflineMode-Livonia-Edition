static string FormatFloat( float value, int decimals ) 
{
    if ( !value.ToString().Contains(".") ) return value.ToString();
	
    string result = "";
    array<string> output = new array<string>;

    value.ToString().Split(".", output);

    if ( output.Count() == 0 ) return value.ToString();

    if ( decimals == 0 ) return output.Get(0);

    string right = output.Get(1).Substring(0, decimals);
    result = output.Get(0) + "." + right;
    return result;
}

static string VectorToString( vector vec )
{
    string result = vec.ToString();
    result.Replace( "<", "" );
    result.Replace( ">", "" );
    result.Replace( ",", "" );

    return result;
}

static string VectorToString( vector vec, int decimals ) 
{
    string result = "";
    result = FormatFloat(vec[0], decimals) + "|" + FormatFloat(vec[1], decimals) + "|" + FormatFloat(vec[2], decimals);

    return result;
}

static TStringArray GetChildrenFromBaseClass( string strConfigName, string strBaseClass )
{
    string child_name = "";
    int count = GetGame().ConfigGetChildrenCount ( strConfigName );
    TStringArray class_names = new TStringArray;

    for (int p = 0; p < count; p++)
    {
        GetGame().ConfigGetChildName ( strConfigName, p, child_name );

        if ( GetGame().IsKindOf(child_name, strBaseClass ) && ( child_name != strBaseClass ) )
        {
            class_names.Insert(child_name);
        }
    }

    return class_names;
}

static TVectorArray GetSpawnPoints()
{
    return { "3175.23 0 6805.85", "11970.94 0 11220.80", "1392.87 0 9664.53", "9768.98 0 8497.65", 
			 "6641.84 0 11130.16", "554.79 0 1127.55", "5790.12 0 5087.65", "11390.37 0 612.61", 
			 "11345.83 0 4397.68", "4993.88 0 9916.66", "10959.82 0 10998.11", "4507.86 0 4803.22", 
			 "6479.31 0 9235.63", "5228.30 0 5567.43", "3668.64 0 8889.91", "2104.29 0 2330.90", 
			 "10078.41 0 6885.64", "8417.17 0 11968.60", "5555.70 0 8724.25", "7813.15 0 10044.03", 
			 "11194.24 0 2453.57", "5937.02 0 6777.02", "3755.38 0 11720.90", "8837.56 0 6614.49", 
			 "4586.78 0 6385.54", "6171.44 0 4091.37", "6291.00 0 8077.26", "4757.12 0 7590.45", 
			 "643.09 0 12108.47", "3362.77 0 2095.52", "3962.44 0 7895.98", "7291.96 0 6487.13", 
			 "8900.85 0 2077.72", "7688.82 0 5238.29", "11323.00 0 10018.24", "2997.42 0 1958.17", 
			 "6300.11 0 10161.06", "11665.42 0 12014.70", "4888.40 0 2211.34", "9268.88 0 10790.26", 
			 "1873.00 0 7341.97", "2979.45 0 1129.89", "10256.57 0 2122.26", "9037.59 0 4390.65", 
			 "865.18 0 5498.05", "8111.64 0 8693.00" };
}

static set< Object > GetObjectsAt( vector from, vector to, Object ignore = NULL, float radius = 0.5, Object with = NULL )
{
    vector contact_pos;
    vector contact_dir;
    int contact_component;

    set< Object > geom = new set< Object >;
    set< Object > view = new set< Object >;

    DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, geom, with, ignore, false, false, ObjIntersectGeom, radius );
    DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, view, with, ignore, false, false, ObjIntersectView, radius );

    if ( geom.Count() > 0 ) 
    {
        return geom;
    }
    if ( view.Count() > 0 ) 
    {
        return view;
    }
    return NULL;
}

static Object GetPointerObject( Object ignore = NULL, float radius = 0.5, Object with = NULL )
{
    vector dir = GetGame().GetPointerDirection();

    vector from = GetGame().GetCurrentCameraPosition();

    vector to = from + ( dir * 10000 );

    auto objs = GetObjectsAt( from, to, ignore, radius, with );

    if( objs.Count() > 0 )
    {
        return objs[ 0 ];
    }

    return NULL;
}

static Object GetCursorObject()
{
    vector rayStart = GetGame().GetCurrentCameraPosition();
    vector rayEnd = rayStart + GetGame().GetCurrentCameraDirection() * 10000;

    auto objs = GetObjectsAt( rayStart, rayEnd );

    if( objs.Count() > 0 )
    {
        return objs[ 0 ];
    }

    return NULL;
}

static vector GetPointerPos()
{
    if ( !GetPlayer() )
    {
        return "0 0 0";
    }

    vector dir = GetGame().GetPointerDirection();

    vector from = GetGame().GetCurrentCameraPosition();

    vector to = from + ( dir * 10000 );

    vector rayStart = from;
    vector rayEnd = to;
    vector hitPos;
    vector hitNormal;
    int hitComponentIndex;
    DayZPhysics.RaycastRV(rayStart, rayEnd, hitPos, hitNormal, hitComponentIndex, NULL, NULL, GetPlayer());

    return hitPos;
}

static vector GetCursorPos()
{
    if ( !GetPlayer() )
    {
        return "0 0 0";
    }

    vector rayStart = GetGame().GetCurrentCameraPosition();
    vector rayEnd = rayStart + GetGame().GetCurrentCameraDirection() * 10000;
    vector hitPos;
    vector hitNormal;
    int hitComponentIndex;
    DayZPhysics.RaycastRV(rayStart, rayEnd, hitPos, hitNormal, hitComponentIndex, NULL, NULL, GetPlayer());

    return hitPos;
}

static void Message( string txt ) 
{
    GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", txt, ""));
}

static Weapon GetWeaponInHands()
{
    Weapon weapon_in_hands;
    if( GetPlayer() && GetPlayer().GetItemInHands() ) Class.CastTo(weapon_in_hands,  GetPlayer().GetItemInHands());

    return weapon_in_hands;
}

static MissionBase GetMission()
{
    return MissionBase.Cast( GetGame().GetMission() );
}

static CommunityOfflineClient GetClientMission()
{
    return CommunityOfflineClient.Cast( GetGame().GetMission() );
}

static CommunityOfflineServer GetServerMission()
{
    return CommunityOfflineServer.Cast( GetGame().GetMission() );
}

static ref PlayerBase GetPlayer()
{
    return GetGame().GetPlayer();
}

static bool SHIFT()
{
    return( ( KeyState( KeyCode.KC_LSHIFT ) > 0 ) || ( KeyState( KeyCode.KC_RSHIFT ) > 0 ) );
}

static bool CTRL()
{
    return( ( KeyState( KeyCode.KC_LCONTROL ) > 0 ) || ( KeyState( KeyCode.KC_RCONTROL ) > 0 ) );
}

static bool ALT()
{
    return( ( KeyState( KeyCode.KC_LMENU ) > 0 ) || ( KeyState( KeyCode.KC_RMENU ) > 0 ) );
}

static bool WINKEY()
{
    return( ( KeyState( KeyCode.KC_LWIN ) > 0 ) || ( KeyState( KeyCode.KC_RWIN ) > 0 ) );
}

/*
static Weapon_Base CreateWeapon( PlayerBase oPlayer )
{
    Weapon_Base oWpn = Weapon_Base.Cast(oPlayer.GetInventory().CreateInInventory( "M4A1_Black" ));
    oWpn.GetInventory().CreateAttachment( "M4_Suppressor" );
    oWpn.GetInventory().CreateAttachment( "M4_RISHndgrd_Black" );
    oWpn.GetInventory().CreateAttachment( "M4_MPBttstck_Black" );
    oWpn.GetInventory().CreateAttachment( "ACOGOptic" );

    return oWpn;
}
*/

static Weapon_Base CreateWeapon( PlayerBase oPlayer, string sWeapon )
{
    Weapon_Base oWpn = Weapon_Base.Cast(oPlayer.GetInventory().CreateInInventory( sWeapon ));
    oWpn.GetInventory().CreateAttachment( "PistolSuppressor" );
    EntityAI optic = oWpn.GetInventory().CreateAttachment( "ReflexOptic" );
    optic.GetInventory().CreateAttachment("Battery9V");

    return oWpn;
}

static PlayerBase CreateCustomDefaultCharacter()
{
    PlayerBase oPlayer = PlayerBase.Cast( GetGame().CreatePlayer( NULL, GetGame().CreateRandomPlayer(), GetSpawnPoints().GetRandomElement(), 0, "NONE") );

    EntityAI item = NULL;

    item = oPlayer.GetInventory().CreateInInventory( "AviatorGlasses" );
    item = oPlayer.GetInventory().CreateInInventory( "MilitaryBeret_UN" );
    item = oPlayer.GetInventory().CreateInInventory( "M65Jacket_Black" );
    item = oPlayer.GetInventory().CreateInInventory( "TacticalGloves_Black" );
    item = oPlayer.GetInventory().CreateInInventory( "HunterPants_Autumn" );
    item = oPlayer.GetInventory().CreateInInventory( "MilitaryBoots_Black" );
    item = oPlayer.GetInventory().CreateInInventory( "AliceBag_Camo" );
    item = oPlayer.GetInventory().CreateInInventory( "Shovel" );

    Weapon_Base oWpn = CreateWeapon( oPlayer, "UMP45" );
    Magazine oMag = Magazine.Cast( oPlayer.GetInventory().CreateInInventory( "Mag_UMP_25Rnd" ) );
    oPlayer.GetDayZPlayerInventory().PostWeaponEvent( new WeaponEventAttachMagazine( oPlayer, oMag ) );
    item = oPlayer.GetInventory().CreateInInventory( "Mag_UMP_25Rnd" );

    oPlayer.LocalTakeEntityToHands( oWpn );
    oPlayer.SetQuickBarEntityShortcut( oWpn, 0, true );
    oPlayer.SetQuickBarEntityShortcut( oMag, 1, true );

    return oPlayer;
}

static string FileAttributeToString( FileAttr attr )
{
    string fileType = "";
    if ( attr & FileAttr.DIRECTORY )
    {
        fileType = fileType + "DIRECTORY";
    }
    if ( attr & FileAttr.HIDDEN )
    {
        fileType = fileType + "HIDDEN";
    }
    if ( attr & FileAttr.READONLY )
    {
        fileType = fileType + "READONLY";
    }
    if ( attr & FileAttr.INVALID )
    {
        fileType = fileType + "INVALID";
    }
    return fileType;
}

static vector SnapToGround(vector pos)
{
    float pos_x = pos[0];
    float pos_z = pos[2];
    float pos_y = GetGame().SurfaceY( pos_x, pos_z );
    vector tmp_pos = Vector( pos_x, pos_y, pos_z );
    tmp_pos[1] = tmp_pos[1] + pos[1];

    return tmp_pos;
}

static bool m_GodMode; // move these to player saves? Edit: Jacob says "yes"
static bool m_OldAiming;
static bool bc_Visible;

static void SnapToGroundNew( Object object ) 
{
    vector pos = object.GetPosition();
    pos[1] = GetGame().SurfaceY(pos[0], pos[2]);
    
    vector clippingInfo[2];
    vector objectBBOX[2];
    
    object.GetCollisionBox( objectBBOX );
    object.ClippingInfo( clippingInfo );

    //float clipY = objectBBOX[1][1] / 2.0//- clippingInfo[0][1];
    //pos[1] = pos[1] + objectBBOX[1][1] - clipY;
    pos[1] = pos[1] + clippingInfo[1][1] / 2.0;//objectBBOX[0][1] - clipY

    object.SetPosition(pos);

    ForceTargetCollisionUpdate( object );
}

static void ForceTargetCollisionUpdate( Object oObj )
{
    if ( !oObj ) return;

    vector roll = oObj.GetOrientation();
    roll [ 2 ] = roll [ 2 ] - 1;
    oObj.SetOrientation( roll );
    roll [ 2 ] = roll [ 2 ] + 1;
    oObj.SetOrientation( roll );
}

static void ToggleCursor()
{
    if ( GetGame().GetInput().HasGameFocus( INPUT_DEVICE_MOUSE ) )
    {
        GetGame().GetInput().ChangeGameFocus( 1 );
        GetGame().GetUIManager().ShowUICursor( true );
    }
    else
    {
        GetGame().GetUIManager().ShowUICursor( false );
        GetGame().GetInput().ResetGameFocus();
    }
}

/*
    Token types:
     0 - error, no token
     1 - defined token (special characters etc. . / * )
     2 - quoted string. Quotes are removed -> TODO
     3 - alphabetic string
     4 - number
     5 - end of line -> TODO
*/
static bool CheckStringType( string str, int type ) 
{
    for(int i = 0; i<str.Length(); i++ ) 
    {
        string character = str.Get(i);
        string token;
        int result = character.ParseStringEx(token);
        if ( result == type ) return true;
    }
    return false;
}

string GetRandomChildFromBaseClass( string strConfigName, string strBaseClass, int minScope = -1 )
{
    string child_name = "";
    int count = GetGame().ConfigGetChildrenCount ( strConfigName );
    array< string > class_names = new array<string>;

    for ( int p = 0; p < count; p++ )
    {
        GetGame().ConfigGetChildName ( strConfigName, p, child_name );

        if( ( minScope != -1 ) && ( GetGame().ConfigGetInt( strConfigName + " " + child_name + " scope" ) < minScope ) ) continue;

        if ( GetGame().IsKindOf( child_name, strBaseClass ) && ( child_name != strBaseClass ) )
        {
            class_names.Insert( child_name );
        }
    }

    return class_names.GetRandomElement();
}
