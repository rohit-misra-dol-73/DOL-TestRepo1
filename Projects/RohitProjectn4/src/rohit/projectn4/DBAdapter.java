package rohit.projectn4;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DBAdapter extends SQLiteOpenHelper {
		private static final String DATABASE_NAME="StudentsDetail";
		private static final int DATABASE_VERSION=1;
		private static final String TABLE_CONTACTS="tablename";
		private Context context;
		private static final String KEY_ID="id";
		private static final String KEY_NAME="name";
		private static final String EMAIL_ID="email_id";
		
		public DBAdapter(Context context){
			super(context,DATABASE_NAME,null,DATABASE_VERSION);
			this.context=context;
		}
		
		public void OnCreate(SQLiteDatabase args0){
			String CREATE_CONTACTS_TABLE = "CREATE_TABLE"+TABLE_CONTACTS+"("+KEY_ID+"INTEGER PRIMARY KEY,"+KEY_NAME+"TEXT,"+EMAIL_ID+"TEXT"+")";
			args0.execSQL(CREATE_CONTACTS_TABLE);
		}
		
		public void onUpgrade(SQLiteDatabase arg0, int oldversion, int newversion){
			arg0.execSQL("DROP TABLE IF EXISTS"+TABLE_CONTACTS);
			onCreate(arg0);
		}
		void insert(String name, String emailId)
		{
			SQLiteDatabase db=this.getWritableDatabase();
			ContentValues values=new ContentValues();
			values.put(KEY_NAME, name);
			values.put(EMAIL_ID, emailId);
			db.insert(TABLE_CONTACTS, null, values);
			db.close();
		}
		public Cursor getInsertedData()
		{
			SQLiteDatabase db=this.getReadableDatabase();
			return db.query(TABLE_CONTACTS, new String[] {KEY_ID,KEY_NAME,EMAIL_ID}, null, null, null, null, null);
		}
		public void clearData(){
			context.deleteDatabase(DATABASE_NAME);
		}

		@Override
		public void onCreate(SQLiteDatabase arg0) {
			// TODO Auto-generated method stub
			
		}
		
}
