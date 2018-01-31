using UnityEngine;
using System.Collections;

public class Gun : MonoBehaviour
{
	public Rigidbody rocket;				// Prefab of the rocket.
	public float speed = 10f;				// The speed the rocket will fire at.
	public GameObject Player;


	private PlayerControl playerCtrl;		// Reference to the PlayerControl script.
	private SetAngle SetAngle;
	private float angle;
	private SetPower SetPower;
	private float power;
	private Animator anim;					// Reference to the Animator component.
	private bool fire=false;
	private int bulletcount=0;


	void Awake()
	{
		// Setting up the references.
		anim = Player.GetComponent<Animator>();
		playerCtrl = Player.GetComponent<PlayerControl>();
		SetAngle = Player.GetComponent<SetAngle>();
		SetPower = Player.GetComponent<SetPower>();
		//print(playerCtrl);
	}


	void Update ()
	{
		angle = SetAngle.angle/10;
		power = SetPower.Power/5;
		//print (SetPower.Stop);
		//print (fire);
		if (playerCtrl.GetState()== false && SetPower.Stop == true && fire==false) 
		{
			bulletcount++;
		}
		// If the fire button is pressed...
		//if(Input.GetButtonDown("Fire1"))
		if(fire==false && bulletcount==1 )
		{
			//print (bulletcount);
			fire=true;
			// ... set the animator Shoot trigger parameter and play the audioclip.
			//anim.SetTrigger("Shoot");
			audio.Play();
			//PlayerControl facing=Player.GetComponent("PlayerControl");
			//print (Player.GetComponent("PlayerControl"));
			// If the player is facing right...
			if(playerCtrl.facingRight)
			{
				// ... instantiate the rocket facing right and set it's velocity to the right. 
				Rigidbody bulletInstance = Instantiate(rocket, transform.position, Quaternion.Euler(new Vector3(0,0,0))) as Rigidbody;
				bulletInstance.velocity = new Vector3(power,  angle, 0);
			}
			else
			{
				//Otherwise instantiate the rocket facing left and set it's velocity to the left.
				Rigidbody bulletInstance = Instantiate(rocket, transform.position, Quaternion.Euler(new Vector3(0,0,180f))) as Rigidbody;
				bulletInstance.velocity = new Vector3(-power, angle, 0);
			}
		}
	}
	public void SetState()
	{
		//print("gun reset");
		fire=false;
		bulletcount=0;
	}
}
