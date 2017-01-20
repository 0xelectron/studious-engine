using UnityEngine;
using System.Collections;

public class GameController : MonoBehaviour {

	public GameObject hazard;
	public Vector3 SpawnValues;
	public int hazardCount;
	public float spawnWait;
	public float startWait;
	public float waveWait;

	public GUIText scoreText;
	public GUIText restartText;
	public GUIText gameOverText;
	public GUIText highscoreText;
	public GUIText bestscoreText;

	private bool gameOver;
	private bool restart;
	private int score;
	int highscore = 0;

	// Use this for initialization
	void Start () {
		gameOver = false;
		restart = false;
		highscore = PlayerPrefs.GetInt("High Score");
		gameOverText.text = "";
		restartText.text =  ""; 
		highscoreText.text = "";
		bestscoreText.text = "Best Score: " + highscore;
		score = 0;
		UpdateScore();
		StartCoroutine( SpawnWaves ());
	}

	void Update(){
		if(score > highscore && gameOver ) //when player dies set highscore = to that score
		{
			highscore = score;
			PlayerPrefs.SetInt("High Score", highscore);
			PlayerPrefs.Save();
			highscoreText.text = "New High Score: " + highscore;
		}    
		if (restart)
		{
			if (Input.GetKeyDown (KeyCode.R))
			{
				Application.LoadLevel (Application.loadedLevel);
			}
		}
	}

	IEnumerator  SpawnWaves () {
		yield return new  WaitForSeconds (startWait);
		while (true) {
			for (int i = 0; i < hazardCount; i++) {
				Vector3 spawnposition = new Vector3 (Random.Range (-SpawnValues.x, SpawnValues.x), SpawnValues.y, SpawnValues.z);
				Quaternion spawnrotation = Quaternion.identity;
				Instantiate (hazard, spawnposition, spawnrotation);
				yield return new  WaitForSeconds (spawnWait);
			}
			yield return new WaitForSeconds (waveWait);
			
			if (gameOver)
			{
				restartText.text = "Press 'R' for Restart";
				restart = true;
				break;
			}
		}
	}

	public void AddScore(int NewScoreValue){
		score += NewScoreValue;
		UpdateScore ();
		
	}

	void UpdateScore(){
		scoreText.text = "Score: " + score;
		}
	public void GameOver(){
		gameOverText.text = "Game Over!";
		gameOver = true;
	}
}
