package rohit.project5;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.widget.Button;
import android.widget.RadioButton;

public class MainActivity extends Activity {
	private Button btn1;
	private RadioButton rdb1, rdb2, rdb3, rdb4;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn1=(Button)findViewById(R.id.button1);
        rdb1=(RadioButton)findViewById(R.id.radioButton1);
        rdb2=(RadioButton)findViewById(R.id.radioButton2);
        rdb3=(RadioButton)findViewById(R.id.radioButton3);
        rdb4=(RadioButton)findViewById(R.id.radioButton4);
        
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
}
