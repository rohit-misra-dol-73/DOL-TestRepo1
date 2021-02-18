package rohit.projectn2;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends Activity {
	Button b1;
	ImageView iv;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		b1=(Button)findViewById(R.id.button1);
		iv=(ImageView)findViewById(R.id.imageView1);
		
		b1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
			Intent intent=new Intent
					(android.provider.MediaStore.ACTION_IMAGE_CAPTURE);
			startActivityForResult(intent, 1);
			}
		});
	}
	
	protected void onActivityResult
	(int requestcode, int resultcode, Intent data){
		super.onActivityResult(requestcode, resultcode, data);
		
		Bitmap bp=(Bitmap)data.getExtras().get("data");
		iv.setImageBitmap(bp);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
