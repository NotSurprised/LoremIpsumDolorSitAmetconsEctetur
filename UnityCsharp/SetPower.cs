using UnityEngine;
using System.Collections;

public class SetPower : MonoBehaviour
{	
	public float Power = 100f;					// The player's Power.
	public float repeatDamagePeriod = 2f;		// How frequently the player can be damaged.
	public float hurtForce = 10f;				// The force with which the player is pushed when hurt.
	public float damageAmount = 10f;			// The amount of damage to take when enemies touch the player
	public GameObject PowerBar1;
	public bool Powerincrease=false;
	public bool Stop=true;
	public GameObject Player;
	private SetAngle SetAngle;
	
	private SpriteRenderer PowerBar;			// Reference to the sprite renderer of the Power bar.
	private float lastHitTime;					// The time at which the player was last hit.
	private Vector3 PowerScale;				// The local scale of the Power bar initially (with full Power).
	//private PlayerControl playerControl;		// Reference to the PlayerControl script.
	private Animator anim;						// Reference to the Animator on the player
	
	
	void Awake ()
	{
		// Setting up references.
		//playerControl = GetComponent<PlayerControl>();
		PowerBar = PowerBar1.GetComponent<SpriteRenderer>();
		anim = GetComponent<Animator>();
		
		// Getting the intial scale of the Powerbar (whilst the player has full Power).
		PowerScale = PowerBar.transform.localScale;

		SetAngle = Player.GetComponent<SetAngle>();
	}
	
	
	void FixedUpdate ()
	{

		if(SetAngle.Stop==true && Stop==false)
		{

			print("11111111111111111111111");
			if (Input.GetKey ("x")) 
			{
				Stop=true;
			}
			if (Powerincrease == true) 
			{
				//print("333333333333333333332");
				Power++;
				//print (Stop);
				if(Power>99f)
				{
					Powerincrease = false;
				}
			} 
			else if(Powerincrease == false)
			{
				//print("4444444444444444444444");
				Power--;
				//print (Stop);
				if(Power<1f)
				{
					Powerincrease = true;
				}
			}
			UpdatePowerBar ();
		}
	}
	
	
	public void UpdatePowerBar ()
	{
		// Set the Power bar's colour to proportion of the way between green and red based on the player's Power.
		PowerBar.material.color = Color.Lerp(Color.red, Color.red, 1 - Power * 0.01f);
		
		// Set the scale of the Power bar to be proportional to the player's Power.
		PowerBar.transform.localScale = new Vector3(PowerScale.x * Power * 0.01f, 1, 1);
	}

	public void Setstate (bool X)
	{
		Stop = X;
	}

	public float GetPower()
	{
		return Power;
	}

}
