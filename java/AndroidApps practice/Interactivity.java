//go to layout and create a new button object

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class Interactivity extends AppCompatActivity{

	public void clickFunction(View view){
		Log.i("Info", "Oh Yes ! It work!!");
	}

	@Override
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

}