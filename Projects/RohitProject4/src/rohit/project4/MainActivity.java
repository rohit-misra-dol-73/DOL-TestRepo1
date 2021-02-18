package rohit.project4;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Toast;

public class MainActivity extends Activity {
	private Button btn;
	private CheckBox chk1, chk2, chk3;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn=(Button)findViewById(R.id.button1);
        chk1=(CheckBox)findViewById(R.id.checkBox1);
        chk2=(CheckBox)findViewById(R.id.checkBox2);
        chk3=(CheckBox)findViewById(R.id.checkBox3);
        checkBoxSelButton();
    }
public void checkBoxSelButton()
{
	btn.setOnClickListener(new View.OnClickListener() {
		
		@Override
		public void onClick(View v) {
			// TODO Auto-generated method stub
		StringBuffer result=new StringBuffer();
		result.append("Option1: ").append(chk1.isChecked());
		result.append("Option2: ").append(chk2.isChecked());
		result.append("Option3: ").append(chk3.isChecked());
		Toast.makeText(MainActivity.this, result.toString(), Toast.LENGTH_LONG).show();
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
