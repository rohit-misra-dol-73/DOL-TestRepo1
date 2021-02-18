package rohit.projectn4;

import android.os.Bundle;
import android.app.Activity;
import android.database.Cursor;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
	
	Button insert, show, delete;
	EditText et1, et2;
	TextView tv1, tv2;
	DBAdapter db;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		insert=(Button)findViewById(R.id.button1);
		show=(Button)findViewById(R.id.button2);
		delete=(Button)findViewById(R.id.button3);
		et1=(EditText)findViewById(R.id.editText1);
		et2=(EditText)findViewById(R.id.editText2);
		
		db=new DBAdapter(this);
		insert.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
			db.insert(et1.getText().toString(), et2.getText().toString());
			Toast.makeText(getBaseContext(), "Data Entered", Toast.LENGTH_LONG).show();
			}
		});
		show.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
			showDataOnToast();
			}
		});
		
		delete.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
			db.clearData();	
			}
		});
	}
	protected void showDataOnToast(){
		Cursor c=db.getInsertedData();
		if(c.moveToFirst())
		{
			do{
				Toast.makeText(this, "id: "+c.getString(0)+"\n"+"Name: "+c.getString(1)+"\n"+"E-mail id: "+c.getString(2), Toast.LENGTH_LONG).show();
			}while(c.moveToNext());
		}
		db.close();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
