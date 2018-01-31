using UnityEngine;
using System.Collections;

public class CameraFollow : MonoBehaviour 
{
	public float xMargin = 1f;		// Distance in the x axis the player can move before the camera follows.
	public float yMargin = 1f;		// Distance in the y axis the player can move before the camera follows.
	public float xSmooth = 8f;		// How smoothly the camera catches up with it's target movement in the x axis.
	public float ySmooth = 8f;		// How smoothly the camera catches up with it's target movement in the y axis.
	public Vector2 maxXAndY;		// The maximum x and y coordinates the camera can have.
	public Vector2 minXAndY;		// The minimum x and y coordinates the camera can have.
	public GameObject Player1;
	public GameObject Player2;
	public int whoisturn=1;

	private Transform player;
	private Transform player1;		// Reference to the player's transform
	private Transform player2;		// Reference to the player's transform.


	void Awake ()
	{
		// Setting up the reference.
		player1 = Player1.transform;
		player2 = Player2.transform;

	}


	bool CheckXMargin()
	{
		if (whoisturn == 1)
		{
			player=player1;
		}
		if (whoisturn == 2)
		{
			player=player2;
		}
		// Returns true if the distance between the camera and the player in the x axis is greater than the x margin.
		return Mathf.Abs(transform.position.x - player.position.x) > xMargin;
	}


	bool CheckYMargin()
	{
		if (whoisturn == 1)
		{
			player=player1;
		}
		if (whoisturn == 2)
		{
			player=player2;
		}
		// Returns true if the distance between the camera and the player in the y axis is greater than the y margin.
		return Mathf.Abs(transform.position.y - player.position.y) > yMargin;
	}


	void FixedUpdate ()
	{
		TrackPlayer();
		print (whoisturn);
	}
	
	
	void TrackPlayer ()
	{
		// By default the target x and y coordinates of the camera are it's current x and y coordinates.
		float targetX = transform.position.x;
		float targetY = transform.position.y;

		// If the player has moved beyond the x margin...
		if(CheckXMargin())
		{
			GameObject Temp = GameObject.Find("rocket 1 1(Clone)");
			if(Temp!=null)
			{
				Transform temp = Temp.transform;
				targetX = Mathf.Lerp(transform.position.x, temp.position.x, xSmooth * Time.deltaTime);
			}
			else if (whoisturn == 1)
			{
				targetX = Mathf.Lerp(transform.position.x, player1.position.x, xSmooth * Time.deltaTime);
			}
			else if (whoisturn == 2)
			{
				targetX = Mathf.Lerp(transform.position.x, player2.position.x, xSmooth * Time.deltaTime);
			}
			// ... the target x coordinate should be a Lerp between the camera's current x position and the player's current x position.
			//targetX = Mathf.Lerp(transform.position.x, player.position.x, xSmooth * Time.deltaTime);
		}
		// If the player has moved beyond the y margin...
		if(CheckYMargin())
		{
			GameObject Temp = GameObject.Find("rocket 1 1(Clone)");
			if(Temp!=null)
			{
				Transform temp = Temp.transform;
				targetX = Mathf.Lerp(transform.position.x, temp.position.x, xSmooth * Time.deltaTime);
			}
			else if (whoisturn == 1)
			{
				targetY = Mathf.Lerp(transform.position.y, player1.position.y, ySmooth * Time.deltaTime);
			}
			else if (whoisturn == 2)
			{
				targetY = Mathf.Lerp(transform.position.y, player2.position.y, ySmooth * Time.deltaTime);
			}
			// ... the target y coordinate should be a Lerp between the camera's current y position and the player's current y position.
			//targetY = Mathf.Lerp(transform.position.y, player.position.y, ySmooth * Time.deltaTime);
		}
		// The target x and y coordinates should not be larger than the maximum or smaller than the minimum.
		targetX = Mathf.Clamp(targetX, minXAndY.x, maxXAndY.x);
		targetY = Mathf.Clamp(targetY, minXAndY.y, maxXAndY.y);

		// Set the camera's position to the target position with the same z component.
		transform.position = new Vector3(targetX, targetY, transform.position.z);
	}

	public void SetState (int state)
	{
		whoisturn = state;
	}
}
