class SpawnAI
{
	SurvivorBotBase m_BotSolder;
	EntityAI itemEnt;
	
	void SpawnAI()
	{
		
	}
	//Create a bot m_BotSolder
	void AddSurvivorAI()
	{
		m_BotSolder = GetGame().CreateObject("BotM_Mirek", "1079.31 445.186 11405.5");
		AddPoint();
		AddLoot();
	}

	void AddLoot()
	{
		if (m_BotSolder)
		{
			//Loot array that the bot will have
		    //string m_RandomLootArray[] = { "Rag","Canteen","TunaCan",""}; //You can add your options
			//-------------------------------------------------------------------------------------------------------------------------
			
			//Adding clothes
			m_BotSolder.GetInventory().CreateInInventory("AliceBag_Green");
			m_BotSolder.GetInventory().CreateInInventory("M65Jacket_Olive");
			m_BotSolder.GetInventory().CreateInInventory("CargoPants_Green");
			m_BotSolder.GetInventory().CreateInInventory("MilitaryBoots_Black");
			m_BotSolder.GetInventory().CreateInInventory("HighCapacityVest_Olive");
			m_BotSolder.GetInventory().CreateInInventory("BallisticHelmet_Green");
			m_BotSolder.GetInventory().CreateInInventory("Balaclava3Holes_Green");
			m_BotSolder.GetInventory().CreateInInventory("TacticalGloves_Green");
			//-------------------------------------------------------------------------------------------------------------------------
			
			//We add our weapons to our options, added here for an example
			int randomWeapon = Math.RandomInt(1, 7);
			
			switch( randomWeapon )
			{	
				case 1: 
				{
					m_BotSolder.AddWeapon("M4A1");
					m_BotSolder.AddWeaponAtt("M4_RISHndgrd");
					m_BotSolder.AddWeaponAtt("M4_MPBttstck");
					m_BotSolder.AddWeaponAtt("ACOGOptic");
					break;
				}
				
				case 2: 
				{
					m_BotSolder.AddWeapon("M4A1");
					m_BotSolder.AddWeaponAtt("M4_RISHndgrd");
					m_BotSolder.AddWeaponAtt("M4_MPBttstck");
					m_BotSolder.AddWeaponAtt("ACOGOptic");
					break;
				}
				
				case 3: 
				{
					m_BotSolder.AddWeapon("M4A1");
					m_BotSolder.AddWeaponAtt("M4_RISHndgrd");
					m_BotSolder.AddWeaponAtt("M4_MPBttstck");
					m_BotSolder.AddWeaponAtt("ACOGOptic");
					break;
				}
				
				case 4: 
				{
					m_BotSolder.AddWeapon("AKM");
					m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
					m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
					break;
				}
				
				case 5: 
				{
					m_BotSolder.AddWeapon("M4A1");
					m_BotSolder.AddWeaponAtt("M4_RISHndgrd");
					m_BotSolder.AddWeaponAtt("M4_MPBttstck");
					m_BotSolder.AddWeaponAtt("ACOGOptic");
					break;
				}
				
				case 6: 
				{
					m_BotSolder.AddWeapon("AKM");
					m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
					m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
					break;
				}
				
				case 7: 
				{
					m_BotSolder.AddWeapon("AKM");
					m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
					m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
					break;
				}
			}	
			//---------------------------------------------------------------------------------------------
			
			//Adding random loot from the array
			/*
			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);	
 
			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);	

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);	

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);

			itemEnt = m_BotSolder.GetInventory().CreateInInventory(m_RandomLootArray[Math.RandomInt(0,43)]);
			SetRandomHealth(itemEnt);
			*/
		   
		   //------------------------------------------------------------------------------------------------
		   
		}
	}
	
	//Setting a random quality of loot
	
	/*
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}
	*/
	//----------------------------------------------------------------------------------------------------------
	
	// Adding checkpoints
	void AddPoint()
	{
 		m_BotSolder.SetUseCheckpoint();
		m_BotSolder.AddCheckpoint("1100.5 447.384 11420.5");
		m_BotSolder.AddCheckpoint("1102.78 439.664 11439.4");
		m_BotSolder.AddCheckpoint("1060.46 443.061 11429.5");
		m_BotSolder.AddCheckpoint("1029.44 437.437 11418");
		m_BotSolder.AddCheckpoint("1024.3 436.965 11386.3");
		m_BotSolder.AddCheckpoint("1068.37 431.434 11360.6");
		m_BotSolder.AddCheckpoint("1079.32 445.14 11397.9");
		m_BotSolder.AddCheckpoint("1098.66 446.336 11394.4");
		m_BotSolder.AddCheckpoint("1104.86 447.895 11423.3");
		m_BotSolder.AddCheckpoint("1100.46 446.362 11426.1");
		m_BotSolder.AddCheckpoint("1102.09 439.768 11439.9");
		m_BotSolder.AddCheckpoint("1073.68 442.078 11440");
		m_BotSolder.AddCheckpoint("1069.41 445.558 11412.6");		
	}	
	//-----------------------------------------------------------------------------------------
};