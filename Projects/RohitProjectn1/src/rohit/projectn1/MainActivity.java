package rohit.projectn1;

import android.os.Bundle;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.Notification;
import android.app.Notification.Builder;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {
	protected static final NotificationManager NotificationManager = null;
	@SuppressWarnings("unused")
	private Button btn;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Button btn=(Button)findViewById(R.id.button1);
		btn.setOnClickListener(new OnClickListener() {
			
			@SuppressLint("NewApi")
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
			Intent i=new Intent();
			PendingIntent pendI=PendingIntent.getActivity(MainActivity.this, 0, i, 0);
			@SuppressWarnings("deprecation")
			Notification noti=new Notification.Builder(MainActivity.this)
			.setTicker("tickerText")
			.setContentTitle("title")
			.setContentText("Hello, I am Rohit")
			.setSmallIcon(R.drawable.image)
			
			.setContentIntent(pendI).getNotification();
			
			noti.flags=Notification.FLAG_AUTO_CANCEL;
			NotificationManager notiManager=(NotificationManager)
					getSystemService(NOTIFICATION_SERVICE);
			notiManager.notify(0, noti);
			
			}

			@SuppressWarnings("unused")
			private Builder setContentIntent(PendingIntent pendI) {
				// TODO Auto-generated method stub
				return null;
			}
		});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
