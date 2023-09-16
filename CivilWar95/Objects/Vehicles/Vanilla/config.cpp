class CfgPatches
{
	class CW95_Vehicles_Vanilla
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};
class CfgVehicles
{
	class CarScript;
	class SimulationModule;
	class Axles;
	class Front;
	class Wheels;
	class Left;
	class Right;
	class Rear;
	
	class OffroadHatchback: CarScript
	{
		fuelCapacity=42;
		fuelConsumption=11;
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=30;
				increaseSpeed[]={0,40,30,20,100,5};
				decreaseSpeed[]={0,80,60,40,90,20};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=0.89999998;
				defaultThrust=0.85000002;
				gentleThrust=0.69999999;
				turboCoef=4;
				gentleCoef=0.75;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.85000002,10,0.80000001,20,0.69999999,40,0.60000002,60,0.63,80,0.66000003,100,0.71999997,120,0.80000001};
				reactionTime=0.30000001;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=2.1800001;
				dragCoefficient=0.56;
			};
			drive="DRIVE_AWD";
			class Engine
			{
				torqueCurve[]={450,0,550,40,1200,80,3400,114,5400,95,8000,0};
				inertia=0.11;
				frictionTorque=100;
				rollingFriction=0.5;
				viscousFriction=0.5;
				rpmIdle=800;
				rpmMin=900;
				rpmClutch=1400;
				rpmRedline=6000;
			};
			class Clutch
			{
				maxTorqueTransfer=240;
				uncoupleTime=0.30000001;
				coupleTime=0.44999999;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=3.526;
				ratios[]={3.6670001,2.0999999,1.3609999,1};
			};
			class CentralDifferential
			{
				ratio=1.5;
				type="DIFFERENTIAL_LOCKED";
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=2000;
					maxHandbrakeTorque=2500;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=4.0999999;
						type="DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness=40000;
						compression=2100;
						damping=7500;
						travelMaxUp=0.088200003;
						travelMaxDown=0.083300002;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="NivaWheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="NivaWheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=1000;
					maxHandbrakeTorque=2500;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=4.0999999;
						type="DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness=40000;
						compression=2200;
						damping=7600;
						travelMaxUp=0.1587;
						travelMaxDown=0.1059;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="NivaWheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="NivaWheel_2_2";
						};
					};
				};
			};
		};
	};
	class CivilianSedan: CarScript
	{
		fuelCapacity=55;
		fuelConsumption=13;
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=35;
				increaseSpeed[]={0,50,10,40,30,30,60,15,100,7,120,4};
				decreaseSpeed[]={0,90,60,60,120,40};
				centeringSpeed[]={0,0,15,30,60,60,100,80};
			};
			class Throttle
			{
				reactionTime=0.34999999;
				defaultThrust=0.64999998;
				gentleThrust=0.55000001;
				turboCoef=6;
				gentleCoef=0.69999999;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.63,10,0.57999998,20,0.55000001,40,0.44999999,50,0.47,80,0.48999998,100,0.50999999,140,0.57999998};
				reactionTime=0.25;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=2.2;
				dragCoefficient=0.44999999;
				downforceCoefficient=0.80000001;
				downforceOffset[]={0,0.40000001,-2.2};
			};
			drive="DRIVE_RWD";
			class Engine
			{
				torqueCurve[]={400,0,1000,157,1700,183,2500,187,4500,147,6000,0};
				inertia=0.44999999;
				frictionTorque=130;
				rollingFriction=1.5;
				viscousFriction=0.5;
				rpmIdle=900;
				rpmMin=1000;
				rpmClutch=1250;
				rpmRedline=4700;
			};
			class Clutch
			{
				maxTorqueTransfer=400;
				uncoupleTime=0.30000001;
				coupleTime=0.30000001;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=3.51;
				ratios[]={3.5,2.26,1.45,1};
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=2000;
					wheelHubMass=10;
					wheelHubRadius=0.15000001;
					class Suspension
					{
						stiffness=60000;
						compression=2100;
						damping=5500;
						travelMaxUp=0.079000004;
						travelMaxDown=0.059999999;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="CivSedanWheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="CivSedanWheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=1600;
					maxHandbrakeTorque=2200;
					wheelHubMass=10;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=4.0999999;
						type="DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness=34000;
						compression=2000;
						damping=5100;
						travelMaxUp=0.086000003;
						travelMaxDown=0.133;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="CivSedanWheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="CivSedanWheel_2_2";
						};
					};
				};
			};
		};
	};
	class Hatchback_02: CarScript
	{
		fuelCapacity=55;
		fuelConsumption=6.5;
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=35;
				increaseSpeed[]={0,50,60,30,100,15};
				decreaseSpeed[]={0,90,60,45,100,20};
				centeringSpeed[]={0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime=0.85000002;
				defaultThrust=0.69999999;
				gentleThrust=0.40000001;
				turboCoef=2.2;
				gentleCoef=0.5;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.69999999,10,0.60000002,20,0.5,40,0.47999999,60,0.5,80,0.57999998,100,0.62,120,0.68000001,150,0.80000001};
				reactionTime=0.2;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=2.1500001;
				dragCoefficient=0.51999998;
				downforceCoefficient=0.0099999998;
				downforceOffset[]={0,0.80000001,-0.69999999};
			};
			drive="DRIVE_FWD";
			class Engine
			{
				torqueCurve[]={850,0,1150,90,2000,130,4400,186,5800,165,7500,0};
				inertia=0.20999999;
				frictionTorque=150;
				rollingFriction=0.2;
				viscousFriction=0.5;
				rpmIdle=1250;
				rpmMin=1500;
				rpmClutch=2000;
				rpmRedline=6250;
			};
			class Clutch
			{
				maxTorqueTransfer=360;
				uncoupleTime=0.25;
				coupleTime=0.34999999;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=3.1670001;
				ratios[]={3.4549999,2.118,1.444,1.1289999,0.912};
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=1800;
					wheelHubMass=5;
					wheelHubRadius=0.125;
					class Differential
					{
						ratio=3.6670001;
						type="DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness=27000;
						compression=2000;
						damping=7500;
						travelMaxUp=0.16;
						travelMaxDown=0.16;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="Hatchback_02_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="Hatchback_02_Wheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=800;
					maxHandbrakeTorque=2000;
					wheelHubMass=5;
					wheelHubRadius=0.125;
					class Suspension
					{
						stiffness=27500;
						compression=2100;
						damping=8000;
						travelMaxUp=0.16;
						travelMaxDown=0.16;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="Hatchback_02_Wheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="Hatchback_02_Wheel_2_2";
						};
					};
				};
			};
		};
	};
	class Sedan_02: CarScript
	{
		fuelCapacity=38;
		fuelConsumption=7;
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=30;
				increaseSpeed[]={0,40,30,20,60,10,100,5};
				decreaseSpeed[]={0,90,60,70,100,50};
				centeringSpeed[]={0,0,15,35,60,65,100,90};
			};
			class Throttle
			{
				reactionTime=0.80000001;
				defaultThrust=0.75;
				gentleThrust=0.5;
				turboCoef=3.8;
				gentleCoef=0.5;
			};
			class Brake
			{
				pressureBySpeed[]={0,1,10,0.94999999,20,0.69999999,40,0.60000002,80,0.75,100,0.80000001,120,0.80000001};
				reactionTime=0.34999999;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=2;
				dragCoefficient=0.34999999;
			};
			drive="DRIVE_RWD";
			class Engine
			{
				torqueCurve[]={600,0,990,50,1800,75,3000,82,5000,71,7000,0};
				inertia=0.2;
				frictionTorque=80;
				rollingFriction=0.5;
				viscousFriction=0;
				rpmIdle=900;
				rpmMin=1000;
				rpmClutch=1500;
				rpmRedline=5750;
			};
			class Clutch
			{
				maxTorqueTransfer=165;
				uncoupleTime=0.1;
				coupleTime=0.30000001;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=3.27;
				ratios[]={3.8,2.1199999,1.41,0.95999998};
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=800;
					wheelHubMass=5;
					wheelHubRadius=0.17;
					class Suspension
					{
						stiffness=25000;
						compression=1600;
						damping=5200;
						travelMaxUp=0.07;
						travelMaxDown=0.079999998;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="Sedan_02_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="Sedan_02_Wheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=600;
					maxHandbrakeTorque=1200;
					wheelHubMass=5;
					wheelHubRadius=0.17;
					class Differential
					{
						ratio=4.2199998;
						type="DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness=21500;
						compression=1800;
						damping=5600;
						travelMaxUp=0.1;
						travelMaxDown=0.1;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="Sedan_02_Wheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="Sedan_02_Wheel_2_2";
						};
					};
				};
			};
		};
	};
	class Truck_01_Base: CarScript
	{
		fuelCapacity=120;
		fuelConsumption=30;
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=35;
				increaseSpeed[]={0,25,50,15};
				decreaseSpeed[]={0,50,50,40};
				centeringSpeed[]={0,25,50,15};
			};
			class Throttle
			{
				reactionTime=0.30000001;
				defaultThrust=0.5;
				gentleThrust=0.2;
				turboCoef=1.25;
				gentleCoef=0.5;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.60000002,10,0.66000003,30,0.63,40,0.60000002,60,0.60000002,80,0.70000005};
				reactionTime=0.30000001;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=5.75;
				dragCoefficient=0.52999997;
			};
			drive="DRIVE_642";
			class Engine
			{
				torqueCurve[]={525,0,800,330,1200,360,1600,340,3000,0};
				inertia=1.15;
				frictionTorque=100;
				rollingFriction=4;
				viscousFriction=2.5;
				rpmIdle=650;
				rpmMin=750;
				rpmClutch=850;
				rpmRedline=2300;
			};
			class Clutch
			{
				maxTorqueTransfer=720;
				uncoupleTime=0.2;
				coupleTime=0.80000001;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=6.2800002;
				ratios[]={6.1900001,3.1300001,1.75,1};
			};
			class CentralDifferential
			{
				ratio=0.75;
				type="DIFFERENTIAL_LOCKED";
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=5500;
					wheelHubMass=25;
					wheelHubRadius=0.30000001;
					class Suspension
					{
						stiffness=65000;
						compression=3000;
						damping=7000;
						travelMaxUp=0.14;
						travelMaxDown=0.15000001;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="Truck_01_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="Truck_01_Wheel_2_1";
						};
					};
				};
				class Middle: Rear
				{
					maxBrakeTorque=5000;
					maxHandbrakeTorque=6000;
					wheelHubMass=45;
					wheelHubRadius=0.30000001;
					class Differential
					{
						ratio=8.3500004;
						type="DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness=55000;
						compression=2500;
						damping=8000;
						travelMaxUp=0.094999999;
						travelMaxDown=0.125;
					};
					class Wheels: Wheels
					{
						class Left
						{
							inventorySlot="Truck_01_Wheel_1_2";
							animTurn="turnmiddleleft";
							animRotation="wheelmiddleleft";
							animDamper="damper_1_2";
							wheelHub="wheel_1_2_damper_land";
						};
						class Right
						{
							inventorySlot="Truck_01_Wheel_2_2";
							animTurn="turnmiddletright";
							animRotation="wheelmiddleright";
							animDamper="damper_2_2";
							wheelHub="wheel_2_2_damper_land";
						};
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=5000;
					maxHandbrakeTorque=6000;
					wheelHubMass=45;
					wheelHubRadius=0.30000001;
					class Differential
					{
						ratio=8.3500004;
						type="DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness=55000;
						compression=2500;
						damping=8000;
						travelMaxUp=0.094999999;
						travelMaxDown=0.125;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_3";
							inventorySlot="Truck_01_Wheel_1_3";
							wheelHub="wheel_1_3_damper_land";
						};
						class Right: Right
						{
							animDamper="damper_2_3";
							inventorySlot="Truck_01_Wheel_2_3";
							wheelHub="wheel_2_3_damper_land";
						};
					};
				};
			};
		};
	};
	class Offroad_02: CarScript
	{
		fuelCapacity=115;
		fuelConsumption=30;
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=30;
				increaseSpeed[]={0,40,30,20,100,10};
				decreaseSpeed[]={0,80,60,40,90,20};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=1;
				defaultThrust=0.85000002;
				gentleThrust=0.69999999;
				turboCoef=4;
				gentleCoef=0.75;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.89999998,10,0.85000002,20,0.80000001,50,0.80000001,80,0.80000001,100,1};
				reactionTime=0.15000001;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=3.05;
				dragCoefficient=0.51999998;
			};
			drive="DRIVE_AWD";
			class Engine
			{
				torqueCurve[]={425,0,500,200,900,313,2000,384,3600,316,5120,0};
				inertia=0.2;
				frictionTorque=90;
				rollingFriction=0.69999999;
				viscousFriction=1;
				rpmIdle=625;
				rpmMin=800;
				rpmClutch=1600;
				rpmRedline=3700;
			};
			class Clutch
			{
				maxTorqueTransfer=650;
				uncoupleTime=0.2;
				coupleTime=0.1;
			};
			class Gearbox
			{
				type="GEARBOX_AUTOMATIC";
				reverse=2.0799999;
				ratios[]={2.48,1.48,1,0.75};
			};
			class CentralDifferential
			{
				ratio=2.1210001;
				type="DIFFERENTIAL_LOCKED";
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=3800;
					maxHandbrakeTorque=5000;
					wheelHubMass=20;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=2.73;
						type="DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness=50000;
						compression=3300;
						damping=4100;
						travelMaxUp=0.25;
						travelMaxDown=0.25;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="Offroad_02_Wheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="Offroad_02_Wheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=3050;
					maxHandbrakeTorque=5000;
					wheelHubMass=20;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=2.73;
						type="DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness=37500;
						compression=3000;
						damping=3600;
						travelMaxUp=0.25;
						travelMaxDown=0.25;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="Offroad_02_Wheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="Offroad_02_Wheel_2_2";
						};
					};
				};
			};
		};
	};
};
