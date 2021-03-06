import java.util.List;
import org.msgpack.annotation.Optional;
import org.msgpack.rpc.Future;

public interface KyotoTycoonClient {
	long count();
	long size();
	void set(byte[] key, byte[] value);
	void set(String key, String value);
	void set(byte[] key, byte[] value, @Optional long xt);
	void set(String key, String value, @Optional long xt);
	void add(byte[] key, byte[] value);
	void add(String key, String value);
	void add(byte[] key, byte[] value, @Optional long xt);
	void add(String key, String value, @Optional long xt);
	void replace(byte[] key, byte[] value);
	void replace(String key, String value);
	void replace(byte[] key, byte[] value, @Optional long xt);
	void replace(String key, String value, @Optional long xt);
	void append(byte[] key, byte[] value);
	void append(String key, String value);
	void append(byte[] key, byte[] value, @Optional long xt);
	void append(String key, String value, @Optional long xt);
	void cas(byte[] key, byte[] ovalue, byte[] nvalue);
	void cas(String key, String ovalue, String nvalue);
	void cas(byte[] key, byte[] ovalue, byte[] nvalue, @Optional long xt);
	void cas(String key, String ovalue, String nvalue, @Optional long xt);
	void remove(byte[] key);
	void remove(String key);
	byte[] get(byte[] key);
	String get(String key);
	List<byte[]> match_prefix(byte[] prefix);
	List<String> match_prefix(String prefix);
	List<byte[]> match_prefix(byte[] prefix, @Optional long max);
	List<String> match_prefix(String prefix, @Optional long max);
	List<byte[]> match_regex(byte[] regex);
	List<String> match_regex(String regex);
	List<byte[]> match_regex(byte[] regex, @Optional long max);
	List<String> match_regex(String regex, @Optional long max);

	Future<Long> countAsync();
	Future<Long> sizeAsync();
	Future<Void> setAsync(byte[] key, byte[] value);
	Future<Void> setAsync(String key, String value);
	Future<Void> setAsync(byte[] key, byte[] value, @Optional long xt);
	Future<Void> setAsync(String key, String value, @Optional long xt);
	Future<Void> addAsync(byte[] key, byte[] value);
	Future<Void> addAsync(String key, String value);
	Future<Void> addAsync(byte[] key, byte[] value, @Optional long xt);
	Future<Void> addAsync(String key, String value, @Optional long xt);
	Future<Void> replaceAsync(byte[] key, byte[] value);
	Future<Void> replaceAsync(String key, String value);
	Future<Void> replaceAsync(byte[] key, byte[] value, @Optional long xt);
	Future<Void> replaceAsync(String key, String value, @Optional long xt);
	Future<Void> appendAsync(byte[] key, byte[] value);
	Future<Void> appendAsync(String key, String value);
	Future<Void> appendAsync(byte[] key, byte[] value, @Optional long xt);
	Future<Void> appendAsync(String key, String value, @Optional long xt);
	Future<Void> casAsync(byte[] key, byte[] ovalue, byte[] nvalue);
	Future<Void> casAsync(String key, String ovalue, String nvalue);
	Future<Void> casAsync(byte[] key, byte[] ovalue, byte[] nvalue, @Optional long xt);
	Future<Void> casAsync(String key, String ovalue, String nvalue, @Optional long xt);
	Future<Void> removeAsync(byte[] key);
	Future<Void> removeAsync(String key);
	Future<byte[]> getAsync(byte[] key);
	Future<String> getAsync(String key);
	Future<List<byte[]>> match_prefixAsync(byte[] prefix);
	Future<List<String>> match_prefixAsync(String prefix);
	Future<List<byte[]>> match_prefixAsync(byte[] prefix, @Optional long max);
	Future<List<String>> match_prefixAsync(String prefix, @Optional long max);
	Future<List<byte[]>> match_regexAsync(byte[] regex);
	Future<List<String>> match_regexAsync(String regex);
	Future<List<byte[]>> match_regexAsync(byte[] regex, @Optional long max);
	Future<List<String>> match_regexAsync(String regex, @Optional long max);
}

