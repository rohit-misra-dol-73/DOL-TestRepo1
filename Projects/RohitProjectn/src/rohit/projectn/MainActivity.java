package rohit.projectn;

import android.net.Uri;
import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {
	@SuppressWarnings("unused")
	private Button btn;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Button btn=(Button)findViewById(R.id.button1);
		btn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
			sendEmail();
			}
		});
		
	}
	protected void sendEmail(){
		
		String TO=("");
		String CC=("");
		Intent emailIntent=new Intent(Intent.ACTION_SEND);
		
		emailIntent.setData(Uri.parse("mailto:"));
		emailIntent.setType("text/plain");
		
		emailIntent.putExtra(Intent.EXTRA_EMAIL, TO);
		emailIntent.putExtra(Intent.EXTRA_CC, CC);
		emailIntent.putExtra(Intent.EXTRA_SUBJECT, "Your Subject");
		emailIntent.putExtra(Intent.EXTRA_TEXT, "E-Mail message here");
		
		try{
			
			startActivity(Intent.createChooser(emailIntent, "Send E-Mail"));
			finish();
		}
		catch(android.content.ActivityNotFoundException ex){
			Toast.makeText(MainActivity.this, "There is no E-Mail client inside", Toast.LENGTH_SHORT).show();
			
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
