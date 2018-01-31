using UnityEngine;
using System.Collections;

public class SetAngle : MonoBehaviour
{	
	public float angle = 100f;					// The player's angle.
	public float repeatDamagePeriod = 2f;		// How frequently the player can be damaged.
	public float hurtForce = 10f;				// The force with which the player is pushed when hurt.
	public float damageAmount = 10f;			// The amount of damage to take when enemies touch the player
	public GameObject angleBar1;
	public bool angleincrease=false;
	public bool Stop=false;

	public GameObject Player;
	private SetAngle SetAngle1;


	private SpriteRenderer angleBar;			// Reference to the sprite renderer of the angle bar.
	private float lastHitTime;					// The time at which the player was last hit.
	private Vector3 angleScale;				// The local scale of the angle bar initially (with full angle).
	//private PlayerControl playerControl;		// Reference to the PlayerControl script.
	private Animator anim;						// Reference to the Animator on the player
	
	void Awake ()
	{
		// Setting up references.
		//playerControl = GetComponent<PlayerControl>();
		angleBar = angleBar1.GetComponent<SpriteRenderer>();
		anim = GetComponent<Animator>();

		// Getting the intial scale of the anglebar (whilst the player has full angle).
		angleScale = angleBar.transform.localScale;

		SetAngle1 = Player.GetComponent<SetAngle>();
	}
	
	
	void FixedUpdate ()
	{
		if(Stop==false)
		{
			if (Input.GetKey ("s")) 
			{
				Stop=true;
			}
			if (angleincrease == true ) 
			{
				angle++;
				if(angle>99f)
				{
					angleincrease = false;
				}
			} 
			else if(angleincrease == false)
			{
				angle--;
				if(angle<1f)
				{
					angleincrease = true;
				}
			}
			UpdateangleBar ();
		}
	}
	
	
	public void UpdateangleBar ()
	{
		// Set the angle bar's colour to proportion of the way between green and red based on the player's angle.
		angleBar.material.color = Color.Lerp(Color.yellow, Color.yellow, 1 - angle * 0.01f);

		// Set the scale of the angle bar to be proportional to the player's angle.
		angleBar.transform.localScale = new Vector3(angleScale.x * angle * 0.01f, 1, 1);
	}

	public void Setstate (bool X)
	{
		Stop= X;
	}

	public float GetAngle()
	{
		return angle;
	}
}

