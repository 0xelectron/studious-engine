using UnityEngine;
using System.Collections;

[System.Serializable]
public class Boundry
{
	public float xMin,xMax,zMin,zMax;
}


public class PlayerControler : MonoBehaviour {

	public float speed;
	public float tilt;
	public Boundry boundry;

	public GameObject shot;
	public Transform shotSpawn;
	public float fireRate;

	private float nextFire;

	void Update()
	{
		if(Input.GetButton("Fire1") && Time .time > nextFire ) 
		{
			nextFire = Time .time + fireRate ;	
			Instantiate (shot, shotSpawn.position, shotSpawn.rotation);
			audio.Play ();
		}
		Vector3 dir = Vector3.zero;
		dir.x = Input.acceleration.x;
		dir.z = Input.acceleration.y; 

		if (dir.sqrMagnitude > 1)
			
			dir.Normalize();  
		
		// Make it move 10 meters per second instead of 10 meters per frame...
		
		dir *= Time.deltaTime;
		
		// Move object
		transform.Translate (dir * speed);
	}

	void FixedUpdate()
	{
		rigidbody.position = new Vector3 
			(
				Mathf.Clamp (rigidbody.position.x , boundry.xMin , boundry.xMax ),
				0.0f , 
				Mathf.Clamp (rigidbody.position.z , boundry.zMin , boundry.zMax)
			); 
	
		rigidbody.rotation = Quaternion.Euler (0.0f , rigidbody.velocity.x * - tilt ,0.0f );
	}
}
